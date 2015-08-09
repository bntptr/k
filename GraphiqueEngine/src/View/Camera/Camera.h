#ifndef CAMERA_H
#define CAMERA_H

#include "ICamera.h"

namespace graphique
{
    class Camera : public ICamera
    {
        protected:
            irr::IrrlichtDevice *device;
            scene::ICameraSceneNode* camera;
        public:
            Camera(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~Camera(){};

            scene::ICameraSceneNode* getCamera() {
                return this->camera;
            }

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add camera
                this->camera =
                    smgr->addCameraSceneNodeFPS(0,100.0f,/*1.2*/0.1f);

                camera->setPosition(core::vector3df(0,0,30)/*core::vector3df(2700*2,255*2,2600*2)*/);
                camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                camera->setFarValue(42000.0f);

                // disable mouse cursor
                device->getCursorControl()->setVisible(false);
            }
    };
} // graphique

#endif
