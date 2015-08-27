#ifndef VIEW_CAMERA_H
#define VIEW_CAMERA_H

#include "ICamera.h"

namespace graphique
{
    class Camera : public ICamera
    {
        protected:
            irr::IrrlichtDevice *device;
            irr::scene::ICameraSceneNode* camera;
            ICursorService* cursor;
            bool splitScreen;
            irr::scene::ICameraSceneNode *cameras[4];

        public:
            Camera(irr::IrrlichtDevice *device, ICursorService *cursor){
                this->device = device;
                this->cursor = cursor;
                this->splitScreen = true;
                this->cameras[0] = 0;
                this->cameras[1] = 0;
                this->cameras[2] = 0;
                this->cameras[3] = 0;
            };
            ~Camera(){};

            irr::scene::ICameraSceneNode* getCameraSceneNode() {
                return this->camera;
            }

            bool build() {
                using namespace irr;
                ViewConfig *config = ViewConfig::getInstance();

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add camera
                this->camera =
                    // RTS : smgr->addCameraSceneNodeFPS(0,100.0f,1.2f/*0.1f*/);
                    // FPS:
                    smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, ID_IsNotPickable, 0, 0, false, 3.f);

                camera->setPosition(core::vector3df(0,0,30)/*core::vector3df(2700*2,255*2,2600*2)*/);
                camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                camera->setFarValue(42000.0f);

                if (this->cursor->getSelector())
                {
                    irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
                        this->cursor->getSelector(),
                        camera,
                        //core::vector3df(30,50,30),
                        irr::core::vector3df(1,1,1),
                        irr::core::vector3df(0,-10,0),
                        irr::core::vector3df(0,30,0)
                    );
                    this->cursor->getSelector()->drop(); // As soon as we're done with the selector, drop it.
                    camera->addAnimator(anim);
                    anim->drop();  // And likewise, drop the animator when we're done referring to it.
                }
                return true;
            }

            bool draw(ITerrainService *terrain, IPopulationService *population) {
                return true;
            }

            /*bool buildA() {
                this->build();
                using namespace irr;
                using namespace core;
                ViewConfig *config = ViewConfig::getInstance();

                config->load();
                const io::path MEDIA = config->getMediaPath();

                scene::ISceneManager* smgr = this->device->getSceneManager();
                // Crée trois caméras fixes et une contrôlée par l'utilisateur.
                // Devant
                this->cameras[0] = smgr->addCameraSceneNode(0, vector3df(50,0,0), vector3df(0,0,0));
                // Dessus
                this->cameras[1] = smgr->addCameraSceneNode(0, vector3df(0,50,0), vector3df(0,0,0));
                // Gauche
                this->cameras[2] = smgr->addCameraSceneNode(0, vector3df(0,0,50), vector3df(0,0,0));
                // Contrôlée par l'utilisateur.
                this->cameras[3] = smgr->addCameraSceneNodeFPS();
                // Ne commence pas à la position de Sydney.
                if (this->cameras[3])
                    this->cameras[3]->setPosition(core::vector3df(-50,0,-50));
                this->device->getCursorControl()->setVisible(false);
                return true;
            }*/

            /*bool drawA () {
                using namespace irr;
                using namespace core;
                ViewConfig *config = ViewConfig::getInstance();
                int ResX=800;
                int ResY=600;
                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = this->device->getVideoDriver();
                scene::ISceneManager* smgr = this->device->getSceneManager();

                // Définit la zone de rendu sur la totalité de l'écran et commence la scène.
                driver->setViewPort(rect<s32>(0, 0, ResX, ResY));
                driver->beginScene(true,true,video::SColor(255,100,100,100));
                // Si la division d'écran est utilisée.
                if (this->splitScreen)
                {
                    // Active la caméra 1.
                    smgr->setActiveCamera(this->cameras[0]);
                    // Définit la zone de rendu sur le premier quart (en haut à gauche).
                    driver->setViewPort(rect<s32>(0,0,ResX/2,ResY/2));
                    // Dessine la scène.
                    smgr->drawAll();
                    // Active la caméra 2.
                    smgr->setActiveCamera(this->cameras[1]);
                    // Définit la zone de rendu sur le deuxième quart (en haut à droite).
                    driver->setViewPort(rect<s32>(ResX/2,0,ResX,ResY/2));
                    // Dessine la scène.
                    smgr->drawAll();
                    // Active la caméra 3.
                    smgr->setActiveCamera(this->cameras[2]);
                    // Définit la zone de rendu sur le troisième quart (en bas à gauche).
                    driver->setViewPort(rect<s32>(0,ResY/2,ResX/2,ResY));
                    // Dessine la scène.
                    smgr->drawAll();
                    // définit la zone de rendu sur le dernier quart (en bas à droite )
                    driver->setViewPort(rect<s32>(ResX/2,ResY/2,ResX,ResY));
                }
                // Active la caméra 4.
                smgr->setActiveCamera(this->cameras[3]);
                return true;
            }*/
    };
} // graphique

#endif
