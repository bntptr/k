#ifndef VIEW_H
#define VIEW_H

#include <irrlicht.h>

#include "IView.h"
#include "EventReceiver/ViewEventReceiver.h"
#include "ViewConfig.h"
#include "Cursor/CursorFactory.h"
#include "Selector/SelectorService.h"
#include "ViewConfig.h"
#include "Environnement/EnvironnementFactory.h"
#include "Camera/CameraFactory.h"
#include "Camera/FPS/FPSFactory.h"
#include "Terrain/TerrainViewFactory.h"
#include "Sky/SkyViewFactory.h"
#include "Building/BuildingFactory.h"
#include "Population/PopulationViewFactory.h"
//#include "Player/PlayerViewFactory.h"

namespace graphique
{
    class View : public IView
    {
        protected:
            irr::IrrlichtDevice *device;
            //SoundService *sound;
            ViewEventReceiver *receiver;
            ICursorEntity *cursor;
            SelectorService *selector;
            IEnvironnement *environnement;
            ICamera *camera;
            ITerrainView *terrain;
            ISkyView *sky;
            IPopulationView *population;
            IBuildingEntity *building;
            //IPlayerView *player;

        public:
            View() {
                this->selector = new SelectorService();
            }
            ~View();

            /**
             * Initialisation des drivers et de la fenêtre principale
             */
            int init() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();

                video::E_DRIVER_TYPE driverType = video::EDT_DIRECT3D9;
                driverType = config->getDriverType();
                const io::path MEDIA = config->getMediaPath();

                irr::SIrrlichtCreationParameters params;
                params.DriverType=driverType;
                std::cout << config->getWindowSizeX() << std::endl;
                config->setWindowSizeX(800);
                config->setWindowSizeY(600);
                params.WindowSize=core::dimension2d<u32>(
                    config->getWindowSizeX(),
                    config->getWindowSizeY()
                );
                IrrlichtDevice* device = createDeviceEx(params);
                this->device = device;

                if (device == 0)
                    return 1; // could not create selected driver.

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);
                return 0;
            }

            int error() {
                std::cout << "View::error A ECRIRE" << std::endl;
                /**
                Vue Irrlicht avec message d'erreur pour l'utilisateur
                */
                return 0;
            }

            /**
             * Construction de tous les éléments de la scène graphique
             */
            int build(business::BusinessInterface *business) {
                std::cout <<"build view !" << std::endl;
                business::IBusinessEntity *entity = business->loadBusinessEntity();

                this->cursor = CursorFactory::createEntity(this->device);
                this->cursor->draw();

                this->environnement = EnvironnementFactory::createEntity(this->device);
                this->environnement->draw();

                this->camera = CameraFactory::createEntity(this->device, this->cursor);
                //this->camera = FPSFactory::createEntity(this->device, this->cursor);
                this->camera->draw();

                business::IGroundEntity *ground = entity->getGround();
                this->terrain = TerrainViewFactory::createEntity(this->device, ground);
                this->terrain->draw(this->camera);

                business::ISkyEntity *skyEntity = entity->getSky();
                this->sky = SkyViewFactory::createEntity(this->device, skyEntity);
                this->sky->draw();

                business::IPopulationEntity *populationEntity = entity->getPopulation();
                this->population = PopulationViewFactory::createEntity(this->device, populationEntity);
                this->population->draw();

                business::IBuildingEntity *buildingEntity = entity->getBuilding();
                this->building = BuildingFactory::createEntity(this->device, buildingEntity);
                this->building->draw();

                // selection par default pour les tests
                IObjectView *obj = this->population->getCharacterFromPlayer();
                this->selector->addToCursorLeft(obj);
                //business::IPlayerEntity *player = entity->getPlayer();
                return 0;
            }

            /**
             *  Exemple Terrain Rendering
             */
            int run() {
                std::cout <<"run View !" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // create event receiver
                this->receiver = new ViewEventReceiver(this);
                this->receiver->setView(this); // segmentation fault si oublié
                device->setEventReceiver(this->receiver);

                /*
                That's it, draw everything.
                */
////////////////////////////////////////////////////////////////////////////////
// POUR LE CURSOR
////////////////////////////////////////////////////////////////////////////////

                video::SMaterial material;
                material.setTexture(0, driver->getTexture("../../../media/faerie3.bmp"));
                material.Lighting = true;
                material.NormalizeNormals = true;

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
                scene::ISceneNode* highlightedSceneNode = 0;
                scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();
////////////////////////////////////////////////////////////////////////////////
                int lastFPS = -1;

                while(device->run())
                if (device->isWindowActive())
                {
                    driver->beginScene(true, true, 0 );

                    smgr->drawAll();
                    env->drawAll();

////////////////////////////////////////////////////////////////////////////////
// POUR LE CURSOR
////////////////////////////////////////////////////////////////////////////////
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
                    ray.start = this->getCamera()->getCamera()->getPosition();
                    ray.end = ray.start + (this->getCamera()->getCamera()->getTarget() - ray.start).normalize() * 1000.0f;

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


////////////////////////////////////////////////////////////////////////////////

                    driver->endScene();

                    // display frames per second in window title
                    int fps = driver->getFPS();
                    if (lastFPS != fps)
                    {
                        core::stringw str = L"Terrain Renderer - Irrlicht Engine [";
                        str += driver->getName();
                        str += "] FPS:";
                        str += fps;
                        // Also print terrain height of current camera position
                        // We can use camera position because terrain is located at coordinate origin
                        str += " Height: ";
                        str += terrain->getTerrain()->getHeight(camera->getCamera()->getAbsolutePosition().X,
                                camera->getCamera()->getAbsolutePosition().Z);

                        device->setWindowCaption(str.c_str());
                        lastFPS = fps;
                    }
                }

                device->drop();
////////////////////////////////////////////////////////////////////////////////
            }

            int runExemple() {
                /*using namespace irr;

                using namespace core;
                using namespace scene;
                using namespace video;
                using namespace io;
                using namespace gui;
                IrrlichtDevice *device =
                    createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
                        false, false, false, 0);

                if (!device)
                    return 1;

                device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

                IVideoDriver* driver = device->getVideoDriver();
                ISceneManager* smgr = device->getSceneManager();
                IGUIEnvironment* guienv = device->getGUIEnvironment();

                guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
                    rect<s32>(10,10,260,22), true);

                IAnimatedMesh* mesh = smgr->getMesh("../../../media/sydney.md2");
                if (!mesh)
                {
                    device->drop();
                    return 1;
                }
                IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

                if (node)
                {
                    node->setMaterialFlag(EMF_LIGHTING, false);
                    node->setMD2Animation(scene::EMAT_STAND);
                    node->setMaterialTexture( 0, driver->getTexture("../../../media/sydney.bmp") );
                }

                smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

                while(device->run())
                {
                    driver->beginScene(true, true, SColor(255,100,101,140));

                    smgr->drawAll();
                    guienv->drawAll();

                    driver->endScene();
                }
                device->drop();
*/
                return 0;
            }

            irr::IrrlichtDevice* setDevice(irr::IrrlichtDevice *dvc) {
                return this->device = dvc;
            }

            SelectorService* getSelector() {
                return this->selector;
            }

            IEnvironnement *getEnvironnement() {
                return this->environnement;
            }

            ICamera *getCamera() {
                return this->camera;
            }

            ITerrainView *getTerrain() {
                return this->terrain;
            }

            ISkyView *getSky() {
                return this->sky;
            }

            IPopulationView *getPopulation() {
                return this->population;
            }

            IBuildingEntity *getBuilding() {
                return this->building;
            }
    };
} // graphique

#endif
