#ifndef RPG_CAMERA_H
#define RPG_CAMERA_H

#include "../Camera.h"

namespace graphique
{
    class CameraRPG : public Camera
    {
        public:
            CameraRPG(irr::IrrlichtDevice *device, ICursorService *cursor) : Camera(device, cursor){
            };
            ~CameraRPG(){};

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
                    smgr->addCameraSceneNodeMaya();       // ajout de la camera FPS
                        /*0,                                     // pas de noeud parent
                        100.0f,                                // vitesse de rotation
                        0.1f,                                  // vitesse de deplacement
                        -1,                                    // pas de numero d'ID
                        keyMap,                                // on change la keymap
                        5                                      // avec une taille de 5
                    );*/
                camera->setPosition(core::vector3df(0,0,30)/*core::vector3df(2700*2,255*2,2600*2)*/);
                camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                camera->setFarValue(42000.0f);

                // disable mouse cursor
                device->getCursorControl()->setVisible(false);
            }
    };
} // graphique

#endif

