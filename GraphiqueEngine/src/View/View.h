#ifndef VIEW_H
#define VIEW_H

#include <irrlicht.h>

#include "IView.h"
#include "Action/Actions.h"
#include "EventReceiver/ViewEventReceiver.h"
#include "ViewConfig.h"
#include "Cursor/CursorServiceFactory.h"
#include "Keyboard/KeyboardServiceFactory.h"
#include "Camera/CameraServiceFactory.h"
#include "Selector/SelectorService.h"
#include "Environnement/EnvironnementServiceFactory.h"
#include "Terrain/TerrainServiceFactory.h"
#include "Sky/SkyServiceFactory.h"
#include "Building/BuildingServiceFactory.h"
#include "Population/PopulationServiceFactory.h"
//#include "Player/PlayerServiceFactory.h"

namespace graphique
{
    class View : public IView
    {
        protected:
            IView *thisInstance;
            EVIEW mode;
            irr::IrrlichtDevice *device;
            ViewEventReceiver *receiver;
            TMap<EVIEW, IAction>* keyMap;

            ICursorService *cursor;
            IKeyboardService *keyboard;
            ISelectorService *selector;
            IEnvironnementService *environnement;
            ICameraService *camera;

            //ISoundService *sound;

            ITerrainService *terrain;
            ISkyService *sky;
            IPopulationService *population;
            IBuildingService *building;
            //IPlayerService *player;

        public:
            View(TMap<EVIEW, IAction>* keyMap) {
                this->thisInstance = this;
                this->keyMap = keyMap;
                this->selector = new SelectorService();
                this->mode = EVIEW_MODE_EDITOR;
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
            int buildGame(business::BusinessInterface *business) {
                std::cout <<"build game !" << std::endl;
                business::IBusinessEntity *entity = business->loadBusinessEntity();

                business::IGroundEntity *ground = entity->getGround();
                this->terrain = TerrainServiceFactory::createService(this->device, ground);
                this->terrain->build(this->camera);

                business::ISkyEntity *skyEntity = entity->getSky();
                this->sky = SkyServiceFactory::createService(this->device, skyEntity);
                this->sky->draw();

                business::IPopulationEntity *populationEntity = entity->getPopulation();
                this->population = PopulationServiceFactory::createService(this->device, populationEntity);
                this->population->draw();

                business::IBuildingEntity *buildingEntity = entity->getBuilding();
                this->building = BuildingServiceFactory::createService(this->device, buildingEntity);
                this->building->build();

                // selection par default pour les tests
                IObjectView *obj = this->population->getCharacterFromPlayer();
                this->selector->addToCursorLeft(obj);
                //business::IPlayerEntity *player = entity->getPlayer();
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
                this->environnement->build();

                this->camera = CameraServiceFactory::createService(this->device, this->cursor);
                this->camera->build();

                this->cursor->setCameraService(this->camera);

                this->buildGame(business);
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

                    this->camera->draw(this->getTerrain(), this->getPopulation());
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
                        str += terrain->getTerrain()->getHeight(camera->getCameraSceneNode()->getAbsolutePosition().X,
                                camera->getCameraSceneNode()->getAbsolutePosition().Z);

                        device->setWindowCaption(str.c_str());
                        lastFPS = fps;
                    }
                }

                device->drop();
            }

            int exit() {
                device->closeDevice();
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

            ITerrainService *getTerrain() {
                return this->terrain;
            }

            ISkyService *getSkyService() {
                return this->sky;
            }

            IPopulationService *getPopulation() {
                return this->population;
            }

            IBuildingService *getBuildingService() {
                return this->building;
            }

            IView* execute(EVIEW key) {
                IAction *k = this->keyMap->get(key);
                if (k) {
                    k->execute(this);
                }
                this->mode = key;
                return this->thisInstance;
            }

            bool onEvent(EVIEW event) {
                this->execute(event);
                return true;
            }

            EVIEW getMode() {
                return this->mode;
            }
    };
} // graphique

#endif
