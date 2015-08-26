#ifndef TWO_D_CAMERA_H
#define TWO_D_CAMERA_H

#include "../Camera.h"

namespace graphique
{
    class Camera2D : public Camera
    {
        public:
            Camera2D(irr::IrrlichtDevice *device, ICursorService *cursor) : Camera(device, cursor){
            };
            ~Camera2D(){};

            bool build() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add camera
                this->camera =
                    smgr->addCameraSceneNodeMaya();
                camera->setPosition(core::vector3df(0,0,30)/*core::vector3df(2700*2,255*2,2600*2)*/);
                camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                camera->setFarValue(42000.0f);

                // disable mouse cursor
                device->getCursorControl()->setVisible(false);
            }
    };
} // graphique

#endif

