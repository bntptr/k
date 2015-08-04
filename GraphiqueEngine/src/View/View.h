#ifndef VIEW_H
#define VIEW_H

#include <irrlicht.h>

#include "IView.h"
#include "ViewEventReceiver.h"
#include "ViewConfig.h"
#include "Environnement/Environnement.h"
#include "Camera/Camera.h"
#include "Terrain/TerrainView.h"
#include "Sky/SkyView.h"
#include "Population/PopulationView.h"
//#include "Player/PlayerView.h"

namespace graphique
{
    class View : public IView
    {
        protected:
            irr::IrrlichtDevice *device;
            ViewEventReceiver *receiver;
            IEnvironnement *environnement;
            ICamera *camera;
            ITerrainView *terrain;
            ISkyView *sky;
            IPopulationView *population;
            //IPlayerView *player;

        public:
            View() {
            }
            ~View();

            int init() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();

                video::E_DRIVER_TYPE driverType = video::EDT_DIRECT3D9;
                driverType = config->getDriverType();
                const io::path MEDIA = config->getMediaPath();

                // create device with full flexibility over creation parameters
                // you can add more parameters if desired, check irr::SIrrlichtCreationParameters
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

            int build(BusinessInterface *business) {
                IBusinessEntity *entity = business->loadBusinessEntity();

                this->environnement = new Environnement(this->device);
                this->environnement->draw();
                this->camera = new Camera(this->device);
                this->camera->draw();

                IGroundEntity *ground = entity->getGround();
                this->terrain = new TerrainView(this->device, ground);
                this->terrain->draw(this->camera);

                ISkyEntity *skyEntity = entity->getSky();
                this->sky = new SkyView(this->device, skyEntity);
                this->sky->draw();

                IPopulationEntity *populationEntity = entity->getPopulation();
                this->population = new PopulationView(this->device, populationEntity);
                this->population->draw();

                //IPlayerEntity *player = entity->getPlayer();
                return 0;
            }

            /**
             *  Exemple Terrain Rendering
             */
            int run() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // create event receiver
                this->receiver = new ViewEventReceiver(
                    terrain->getTerrain(),
                    sky->getSkyBox(),
                    sky->getSkyDome()
                );
                device->setEventReceiver(this->receiver);

                /*
                That's it, draw everything.
                */
////////////////////////////////////////////////////////////////////////////////
                int lastFPS = -1;

                while(device->run())
                if (device->isWindowActive())
                {
                    driver->beginScene(true, true, 0 );

                    smgr->drawAll();
                    env->drawAll();

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
      //RequestController*  draw(RequestController* request) {
      /*void draw() {
    	  // charge la vue
    	  if (true) {

              // affecte le receiver de la vue
    		  this->device->setEventReceiver(this->receiver);

    	  // récupère les driver, manager, ...
    	  irr::video::IVideoDriver* driver = this->device->getVideoDriver();
		  irr::scene::ISceneManager* smgr = this->device->getSceneManager();
		  irr::gui::IGUIEnvironment* guienv = this->device->getGUIEnvironment();

    	  // execute la vue
    	  while(device->run())
			{
				driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
				smgr->drawAll();
				guienv->drawAll();
				driver->endScene();

		        //this->frame();
			}
    	  }
    	  //return this->afterAction(request);
      }*/

        irr::IrrlichtDevice* setDevice(irr::IrrlichtDevice *dvc) {
            return this->device = dvc;
        }
    };
} // graphique

#endif
