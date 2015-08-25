#ifndef VIEW_H
#define VIEW_H

#include <irrlicht.h>

#include "IView.h"
#include "EventReceiver/ViewEventReceiver.h"
#include "ViewConfig.h"
#include "Cursor/CursorServiceFactory.h"
#include "Keyboard/KeyboardServiceFactory.h"
#include "Camera/CameraServiceFactory.h"
#include "Selector/SelectorService.h"
#include "ViewConfig.h"
#include "Environnement/EnvironnementServiceFactory.h"
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
            ViewEventReceiver *receiver;

            ICursorService *cursor;
            IKeyboardService *keyboard;
            ISelectorService *selector;
            IEnvironnementService *environnement;
            ICameraService *camera;

            //ISoundService *sound;

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

                this->cursor = CursorServiceFactory::createService(this->device, this);
                this->cursor->build();

                this->keyboard = KeyboardServiceFactory::createService(this);

                this->environnement = EnvironnementServiceFactory::createService(this->device);
                this->environnement->draw();

                this->camera = CameraServiceFactory::createService(this->device, this->cursor);
                //this->camera = FPSFactory::createEntity(this->device, this->cursor);
                this->camera->build();

                this->cursor->setCameraService(this->camera);

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
                int lastFPS = -1;

                while(device->run())
                if (device->isWindowActive())
                {
                    driver->beginScene(true, true, 0 );

                    this->camera->draw();
                    smgr->drawAll();
                    env->drawAll();
                    this->cursor->draw();

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
            }

            irr::IrrlichtDevice* setDevice(irr::IrrlichtDevice *dvc) {
                return this->device = dvc;
            }

            ISelectorService* getSelector() {
                return this->selector;
            }

            ICursorService *getCursorService() {
                return this->cursor;
            }

            IKeyboardService *getKeyboardService() {
                return this->keyboard;
            }

            IEnvironnementService *getEnvironnementService() {
                return this->environnement;
            }

            ICameraService* getCameraService() {
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
