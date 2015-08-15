#ifndef VIEW_FPS_H
#define VIEW_FPS_H

#include <irrlicht.h>

#include "View.h"

enum
{
	// I use this ISceneNode ID to indicate a scene node that is
	// not pickable by getSceneNodeAndCollisionPointFromRay()
	ID_IsNotPickable = 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be picked by ray selection.
	IDFlag_IsPickable = 1 << 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be highlighted.  In this example, the
	// homonids can be highlighted, but the level mesh can't.
	IDFlag_IsHighlightable = 1 << 1
};

namespace graphique
{
    class ViewFPS : public View
    {
        public:
            ViewFPS() {};
            ~ViewFPS();

            int run()
            {
                // let user select driver type

                video::E_DRIVER_TYPE driverType;

                printf("Please select the driver you want for this example:\n"\
                    " (a) Direct3D 9.0c\n (b) Direct3D 8.1\n (c) OpenGL 1.5\n"\
                    " (d) Software Renderer\n (e) Burning's Software Renderer\n"\
                    " (f) NullDevice\n (otherKey) exit\n\n");

                char i;
                std::cin >> i;

                switch(i)
                {
                    case 'a': driverType = video::EDT_DIRECT3D9;break;
                    case 'b': driverType = video::EDT_DIRECT3D8;break;
                    case 'c': driverType = video::EDT_OPENGL;   break;
                    case 'd': driverType = video::EDT_SOFTWARE; break;
                    case 'e': driverType = video::EDT_BURNINGSVIDEO;break;
                    case 'f': driverType = video::EDT_NULL;     break;
                    default: return 0;
                }

                // create device

                IrrlichtDevice *device =
                    createDevice(driverType, core::dimension2d<u32>(1280, 960), 16, false);

                if (device == 0)
                    return 1; // could not create selected driver.

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();

                device->getFileSystem()->addZipFileArchive("../../../media/map-20kdm2.pk3");

                scene::IAnimatedMesh* q3levelmesh = smgr->getMesh("20kdm2.bsp");
                scene::IMeshSceneNode* q3node = 0;

                // The Quake mesh is pickable, but doesn't get highlighted.
                if (q3levelmesh)
                    q3node = smgr->addOctTreeSceneNode(q3levelmesh->getMesh(0), 0, IDFlag_IsPickable);


                scene::ITriangleSelector* selector = 0;

                if (q3node)
                {
                    q3node->setPosition(core::vector3df(-1350,-130,-1400));

                    selector = smgr->createOctTreeTriangleSelector(
                            q3node->getMesh(), q3node, 128);
                    q3node->setTriangleSelector(selector);
                    // We're not done with this selector yet, so don't drop it.
                }


            //////**************************************

                // Set a jump speed of 3 units per second, which gives a fairly realistic jump
                // when used with the gravity of (0, -10, 0) in the collision response animator.
                scene::ICameraSceneNode* camera =
                    smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, ID_IsNotPickable, 0, 0, true, 3.f);
                camera->setPosition(core::vector3df(50,50,-60));
                camera->setTarget(core::vector3df(-70,30,-60));

                if (selector)
                {
                    scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
                        selector, camera, core::vector3df(30,50,30),
                        core::vector3df(0,-10,0), core::vector3df(0,30,0));
                    selector->drop(); // As soon as we're done with the selector, drop it.
                    camera->addAnimator(anim);
                    anim->drop();  // And likewise, drop the animator when we're done referring to it.
                }

                // Now I create three animated characters which we can pick, a dynamic light for
                // lighting them, and a billboard for drawing where we found an intersection.

                // First, let's get rid of the mouse cursor.  We'll use a billboard to show
                // what we're looking at.
                device->getCursorControl()->setVisible(false);

                // Add the billboard.//panneau d'affichage
                scene::IBillboardSceneNode * bill = smgr->addBillboardSceneNode();
                bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR );
                bill->setMaterialTexture(0, driver->getTexture("../../../media/particle.bmp"));//le truc rouge :)
                bill->setMaterialFlag(video::EMF_LIGHTING, false);
                bill->setMaterialFlag(video::EMF_ZBUFFER, false);
                bill->setSize(core::dimension2d<f32>(20.0f, 20.0f));
                bill->setID(ID_IsNotPickable); // This ensures that we don't accidentally ray-pick it

                /* Add 3 animated hominids, which we can pick using a ray-triangle intersection.
                They all animate quite slowly, to make it easier to see that accurate triangle
                selection is being performed. */
                scene::IAnimatedMeshSceneNode* node = 0;
                //==========================================================================
                //                           fée
                // Add an MD2 node, which uses vertex-based animation.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/faerie.md2"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setPosition(core::vector3df(-70,-15,-120)); // Put its feet on the floor.
                node->setScale(core::vector3df(2, 2, 2)); // Make it appear realistically scaled
                node->setMD2Animation(scene::EMAT_POINT);
                node->setAnimationSpeed(20.f);
                video::SMaterial material;
                material.setTexture(0, driver->getTexture("../../../media/faerie3.bmp"));
                material.Lighting = true;
                material.NormalizeNormals = true;
                node->getMaterial(0) = material;

                // Now create a triangle selector for it.  The selector will know that it
                // is associated with an animated node, and will update itself as necessary.
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop(); // We're done with this selector, so drop it now.
                //==========================================================================
                //                           NAIN 1
                // This X files uses skeletal animation, but without skinning.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/dwarf.x"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setPosition(core::vector3df(-70,-66,0)); // Put its feet on the floor.
                node->setRotation(core::vector3df(0,-90,0)); // And turn it towards the camera.
                node->setAnimationSpeed(20.f);
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();
                //==========================================================================
                //                           NAIN 2
                // This X files uses skeletal animation, but without skinning.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/dwarf.x"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setPosition(core::vector3df(-100,-66,0)); // Put its feet on the floor.
                node->setRotation(core::vector3df(0,-90,0)); // And turn it towards the camera.
                node->setAnimationSpeed(30.f);
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();
                //==========================================================================
                //                           NAIN 3
                // This X files uses skeletal animation, but without skinning.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/dwarf.x"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setPosition(core::vector3df(-170,-66,0)); // Put its feet on the floor.
                node->setRotation(core::vector3df(0,-90,0)); // And turn it towards the camera.
                node->setAnimationSpeed(10.f);
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();

                //==========================================================================
                //                           NAIN 4
                // This X files uses skeletal animation, but without skinning.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/dwarf.x"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setPosition(core::vector3df(-400,66,0)); // emplacement du nain sur le sol
                node->setRotation(core::vector3df(0,45,0)); //direction du nain(semble etre comparable a une sphere et des degré qu'on modifierais)
                node->setAnimationSpeed(20.f);//vitesse de l'animation
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();
                //==========================================================================
                //                           NINJA
                // And this B3D file uses skinned skeletal animation.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setScale(core::vector3df(10, 10, 10));
                node->setPosition(core::vector3df(-70,-66,-60));
                node->setRotation(core::vector3df(0,90,0));
                node->setAnimationSpeed(10.f);
                node->getMaterial(0).NormalizeNormals = true;
                // Just do the same as we did above.
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();
                //==========================================================================
                //                           NINJA 2
                // And this B3D file uses skinned skeletal animation.
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                node->setScale(core::vector3df(10, 10, 10));
                node->setPosition(core::vector3df(70,-66,-60)); //ils sont a une hauteur de -66
                node->setRotation(core::vector3df(0,-90,0));
                node->setAnimationSpeed(5.f); //vitesse de l'animation
                node->getMaterial(0).NormalizeNormals = true;
                // Just do the same as we did above. //pour le triangle rouge??
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();
            //******************************************************************************
            //REMARQUE: node semble bizarrement pouvoir etre réutilisable plusieurs fois
            //==============================================================================
            //                                NINJA - MARCHE
                scene::IAnimatedMeshSceneNode* anms =
                    smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"));

                if (anms) //anms est le nom du noeud du ninja
                {
                    scene::ISceneNodeAnimator* anim = //il n'a pas de position car il se déplace en tre deux points
                        smgr->createFlyStraightAnimator(core::vector3df(350,-66,60),
                        core::vector3df(-200,-66,60), 10000, true); //les deux points de déplacement /pas de répétition du trajet.
                    if (anim)
                    {
                        anms->addAnimator(anim);
                        anim->drop();
                    }
                    anms->setMaterialFlag(video::EMF_LIGHTING, false);//éclairage

                    anms->setFrameLoop(0, 13);
                    anms->setAnimationSpeed(10);
            //		anms->setMD2Animation(scene::EMAT_RUN);

                    anms->setScale(core::vector3df(10,10,10)); //taille du ninja
                    anms->setRotation(core::vector3df(0,-90,0)); //direction du ninja
            //		anms->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));

                }

            //==============================================================================
            //                                NINJA 2 - MARCHE
                scene::IAnimatedMeshSceneNode* anms2 =
                    smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"));

                if (anms2) //anms est le nom du noeud du ninja
                {
                    scene::ISceneNodeAnimator* anim = //il n'a pas de position car il se déplace en tre deux points
                        smgr->createFlyStraightAnimator(core::vector3df(0,-66,200),
                        core::vector3df(0,-66,-200), 9000, true); //les deux points de déplacement /pas de répétition du trajet.
                    if (anim)
                    {
                        anms2->addAnimator(anim);
                        anim->drop();
                    }
                    anms2->setMaterialFlag(video::EMF_LIGHTING, false);//éclairage

                    anms2->setFrameLoop(0, 13);
                    anms2->setAnimationSpeed(15);
            //		anms2->setMD2Animation(scene::EMAT_RUN);

                    anms2->setScale(core::vector3df(9,9,9)); //taille du ninja
                    anms2->setRotation(core::vector3df(0,-180,0)); //direction du ninja
            //		anms2->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));

                }
            //==============================================================================
            //                                NINJA 3 - MARCHE
                scene::IAnimatedMeshSceneNode* anms3 =
                    smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"));

                if (anms3) //anms est le nom du noeud du ninja
                {
                    scene::ISceneNodeAnimator* anim = //il n'a pas de position car il se déplace en tre deux points
                        smgr->createFlyStraightAnimator(core::vector3df(50,-66,0),
                        core::vector3df(50,-66,-0), 1000, true); //les deux points de déplacement /pas de répétition du trajet.
                    if (anim)
                    {
                        anms3->addAnimator(anim);
                        anim->drop();
                    }
                    anms3->setMaterialFlag(video::EMF_LIGHTING, false);//éclairage

                    anms3->setFrameLoop(0, 13);
                    anms3->setAnimationSpeed(15);
            //		anms3->setMD2Animation(scene::EMAT_RUN);

                    anms3->setScale(core::vector3df(9,9,9)); //taille du ninja
                    anms3->setRotation(core::vector3df(0,-180,0)); //direction du ninja
            //		anms3->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));

                }
            //==============================================================================
            //                                NINJA 4 - MARCHE
                scene::IAnimatedMeshSceneNode* anms4 =
                    smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"));

                if (anms4) //anms est le nom du noeud du ninja
                {
                    scene::ISceneNodeAnimator* anim = //il n'a pas de position car il se déplace en tre deux points
                        smgr->createFlyStraightAnimator(core::vector3df(0,0,0),
                        core::vector3df(0,0,-0), 1000, true); //les deux points de déplacement /pas de répétition du trajet.
                    if (anim)
                    {
                        anms4->addAnimator(anim);
                        anim->drop();
                    }
                    anms4->setMaterialFlag(video::EMF_LIGHTING, false);//éclairage

                    anms4->setFrameLoop(0, 13);
                    anms4->setAnimationSpeed(15);
            //		anms4->setMD2Animation(scene::EMAT_RUN);

                    anms4->setScale(core::vector3df(9,9,9)); //taille du ninja
                    anms4->setRotation(core::vector3df(0,-180,0)); //direction du ninja
            //		anms4->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));

                }


    //==========================================================================
	//                           Gun
	// Add an MD2 node, which uses vertex-based animation.
	node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/gun.md2"),
						0, IDFlag_IsPickable | IDFlag_IsHighlightable);
	node->setPosition(core::vector3df(0,15,0)); // Put its feet on the floor.
	node->setScale(core::vector3df(1, 1, 1)); // Make it appear realistically scaled
    node->setMD2Animation(scene::EMAT_RUN); //EMAT_QUOI???  POINT, RUN  voir IAnimatedMeshMD2.h
	/*node->setAnimationSpeed(20.f);*/
	//video::SMaterial material;//redéclaration, a donc virer
	material.setTexture(0, driver->getTexture("../../../media/gun.jpg"));
	material.Lighting = true;
	material.NormalizeNormals = true;
	node->getMaterial(0) = material;

	// Now create a triangle selector for it.  The selector will know that it
	// is associated with an animated node, and will update itself as necessary.
	selector = smgr->createTriangleSelector(node);
	node->setTriangleSelector(selector);
	selector->drop(); // We're done with this selector, so drop it now.
                //==========================================================================
                //                           FIN
                material.setTexture(0, 0);
                material.Lighting = false;

            /////////////////************************
                // Add a light, so that the unselected nodes aren't completely dark.
                scene::ILightSceneNode * light = smgr->addLightSceneNode(0, core::vector3df(-60,100,400),
                    video::SColorf(1.0f,1.0f,1.0f,1.0f), 600.0f);
                light->setID(ID_IsNotPickable); // Make it an invalid target for selection.

                // Remember which scene node is highlighted
                scene::ISceneNode* highlightedSceneNode = 0;
                scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();
                int lastFPS = -1;

                while(device->run())
                if (device->isWindowActive())
                {
                    driver->beginScene(true, true, 0);
                    smgr->drawAll();

                    // Unlight any currently highlighted scene node
                    if (highlightedSceneNode)
                    {
                        highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, true);
                        highlightedSceneNode = 0;
                    }

                    // All intersections in this example are done with a ray cast out from the camera to
                    // a distance of 1000.  You can easily modify this to check (e.g.) a bullet
                    // trajectory or a sword's position, or create a ray from a mouse click position using
                    // ISceneCollisionManager::getRayFromScreenCoordinates()
                    core::line3d<f32> ray;
                    ray.start = camera->getPosition();
                    ray.end = ray.start + (camera->getTarget() - ray.start).normalize() * 1000.0f;

                    // Tracks the current intersection point with the level or a mesh
                    core::vector3df intersection;
                    // Used to show with triangle has been hit
                    core::triangle3df hitTriangle;

                    // This call is all you need to perform ray/triangle collision on every scene node
                    // that has a triangle selector, including the Quake level mesh.  It finds the nearest
                    // collision point/triangle, and returns the scene node containing that point.
                    // Irrlicht provides other types of selection, including ray/triangle selector,
                    // ray/box and ellipse/triangle selector, plus associated helpers.
                    // See the methods of ISceneCollisionManager
                    scene::ISceneNode * selectedSceneNode =
                        collMan->getSceneNodeAndCollisionPointFromRay(
                                ray,
                                intersection, // This will be the position of the collision
                                hitTriangle, // This will be the triangle hit in the collision
                                IDFlag_IsPickable, // This ensures that only nodes that we have
                                        // set up to be pickable are considered
                                0); // Check the entire scene (this is actually the implicit default)

                    // If the ray hit anything, move the billboard to the collision position
                    // and draw the triangle that was hit.
                    if(selectedSceneNode)
                    {
                        bill->setPosition(intersection);

                        // We need to reset the transform before doing our own rendering.
                        driver->setTransform(video::ETS_WORLD, core::matrix4());
                        driver->setMaterial(material);
                        driver->draw3DTriangle(hitTriangle, video::SColor(0,255,0,0));

                        // We can check the flags for the scene node that was hit to see if it should be
                        // highlighted. The animated nodes can be highlighted, but not the Quake level mesh
                        if((selectedSceneNode->getID() & IDFlag_IsHighlightable) == IDFlag_IsHighlightable)
                        {
                            highlightedSceneNode = selectedSceneNode;

                            // Highlighting in this case means turning lighting OFF for this node,
                            // which means that it will be drawn with full brightness.
                            highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
                        }
                    }

                    // We're all done drawing, so end the scene.
                    driver->endScene();

                    int fps = driver->getFPS();

                    if (lastFPS != fps)
                    {
                        core::stringw str = L"Collision detection example - Irrlicht Engine [";
                        str += driver->getName();
                        str += "] FPS:";
                        str += fps;

                        device->setWindowCaption(str.c_str());
                        lastFPS = fps;
                    }
                }

                device->drop();

                return 0;
            }
    };
} // graphique

#endif
