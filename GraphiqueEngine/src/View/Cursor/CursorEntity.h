#ifndef VIEW_CURSOR_ENTITY_H
#define VIEW_CURSOR_ENTITY_H

#include "CursorConfig.h"
#include "ICursorEntity.h"
#include "../ViewConfig.h"
//#include "Action/IAction.h"
#include "../Camera/ICamera.h"

namespace graphique
{
    class CursorEntity : public ICursorEntity
    {
        protected:
            irr::IrrlichtDevice *device;
            irr::scene::ITriangleSelector* selector;
            irr::scene::IBillboardSceneNode * bill;
            irr::scene::ISceneNode* highlightedSceneNode;
            irr::scene::ISceneCollisionManager* collMan;
            ICamera *camera;


        public:
            CursorEntity(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~CursorEntity(){};

            bool build() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();


                this->selector = 0;

                //////**************************************

                // Set a jump speed of 3 units per second, which gives a fairly realistic jump
                // when used with the gravity of (0, -10, 0) in the collision response animator.
                /*scene::ICameraSceneNode* camera =
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
                }*/
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
            /////////////////************************
                // Add a light, so that the unselected nodes aren't completely dark.
                scene::ILightSceneNode * light = smgr->addLightSceneNode(0, core::vector3df(-60,100,400),
                    video::SColorf(1.0f,1.0f,1.0f,1.0f), 600.0f);
                light->setID(ID_IsNotPickable); // Make it an invalid target for selection.

                // Remember which scene node is highlighted
                this->highlightedSceneNode = 0;
                this->collMan = smgr->getSceneCollisionManager();
                this->bill = bill;

            }

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                video::SMaterial material;
                //material.setTexture(0, driver->getTexture("../../../media/faerie3.bmp"));
                //material.Lighting = true;
                //material.NormalizeNormals = true;

                // Unlight any currently highlighted scene node
                if (this->highlightedSceneNode)
                {
                    this->highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, true);
                    this->highlightedSceneNode = 0;
                }

                // All intersections in this example are done with a ray cast out from the camera to
                // a distance of 1000.  You can easily modify this to check (e.g.) a bullet
                // trajectory or a sword's position, or create a ray from a mouse click position using
                // ISceneCollisionManager::getRayFromScreenCoordinates()
                core::line3d<f32> ray;
                ray.start = this->camera->getCamera()->getPosition();
                ray.end = ray.start + (this->camera->getCamera()->getTarget() - ray.start).normalize() * 10000.0f;

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
                    this->bill->setPosition(intersection);

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
                        std::cout << "selected : " << selectedSceneNode->getID() << std::endl;
                        std::cout << "intersection : " << intersection.X << ", "<< intersection.Y << ", "<< intersection.Z << std::endl;
                    }
                }

                return true;
            }

/**
numerator:
EMIE_LMOUSE_PRESSED_DOWN 	Left mouse button was pressed down.
EMIE_RMOUSE_PRESSED_DOWN 	Right mouse button was pressed down.
EMIE_MMOUSE_PRESSED_DOWN 	Middle mouse button was pressed down.
EMIE_LMOUSE_LEFT_UP 	Left mouse button was left up.
EMIE_RMOUSE_LEFT_UP 	Right mouse button was left up.
EMIE_MMOUSE_LEFT_UP 	Middle mouse button was left up.
EMIE_MOUSE_MOVED 	The mouse cursor changed its position.
EMIE_MOUSE_WHEEL 	The mouse wheel was moved. Use Wheel value in event data to find out in what direction and how fast.
EMIE_MOUSE_DOUBLE_CLICK 	Mouse double click. This event is generated after the second EMIE_LMOUSE_PRESSED_DOWN event.
EMIE_MOUSE_TRIPLE_CLICK 	Mouse triple click. This event is generated after the third EMIE_LMOUSE_PRESSED_DOWN event.
EMIE_COUNT 	No real event. Just for convenience to get number of events.
*/
            bool oneEvent(const irr::SEvent& event) {
                switch(event.MouseInput.Event)
                {
                    case irr::EMIE_LMOUSE_PRESSED_DOWN:
                        /*MouseState.LeftButtonDown = true;
                        cursor->setCgDown();
                        cursor->run();*/
                        break;
                    //Pour ctrl+clic droit ou gauche ? je sais pas...
                    // si comme cursor créer une classe clavier qui retiendra si une touche est ou non appuyée;
                    case irr::EMIE_LMOUSE_LEFT_UP:              //bouton gauche clic relaché
                        /*MouseState.LeftButtonDown = false;
                        cursor->setCgUp();
                        cursor->run();*/
                        break;

                    case irr::EMIE_RMOUSE_PRESSED_DOWN:
                        /*MouseState.LeftButtonDown = true;
                        cursor->setCdDown();
                        cursor->run();*/
                        break;

                    case irr::EMIE_RMOUSE_LEFT_UP:              //bouton droit clic relaché
                        /*MouseState.LeftButtonDown = false;
                        cursor->setCdUp();
                        cursor->run();*/
                        break;

                    case irr::EMIE_MOUSE_MOVED:
                        /*MouseState.Position.X = event.MouseInput.X;
                        MouseState.Position.Y = event.MouseInput.Y;
                        cursor->setX(event.MouseInput.X); //si marche pas utiliser "core::position2di Position;" dans MyCursor
                        cursor->setY(event.MouseInput.Y);
                        cursor->run();*/
                        break;

                    case irr::EMIE_MOUSE_WHEEL:

                        break;

                    case irr::EMIE_MOUSE_DOUBLE_CLICK:

                        break;

                    case irr::EMIE_MOUSE_TRIPLE_CLICK:

                        break;


                    case irr::EMIE_COUNT:

                        break;

                    default:
                        // We won't use the wheel
                        break;
                }
                return true;
            }

            irr::scene::ITriangleSelector* getSelector() {
                return this->selector;
            }

            ICursorEntity* setCamera(ICamera *camera) {
                this->camera = camera;
                ICursorEntity* thisInstance = this;
                return thisInstance;
            }
    };
} // graphique

#endif


