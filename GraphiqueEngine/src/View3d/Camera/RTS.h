#ifndef RTS_CAMERA_H
#define RTS_CAMERA_H

#include "../Camera.h"

namespace graphique
{
    class CameraRTS : public Camera
    {
        public:
            CameraRTS(irr::IrrlichtDevice *device, ICursorService *cursor) : Camera(device, cursor){
            };
            ~CameraRTS(){};

            bool build() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                irr::SKeyMap keyMap[5];                    // re-assigne les commandes
                keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
                keyMap[0].KeyCode = irr::KEY_KEY_W;        // w
                keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
                keyMap[1].KeyCode = irr::KEY_KEY_S;        // s
                keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
                keyMap[2].KeyCode = irr::KEY_KEY_A;        // a
                keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
                keyMap[3].KeyCode = irr::KEY_KEY_D;        // d
                keyMap[4].Action = irr::EKA_JUMP_UP;       // saut
                keyMap[4].KeyCode = irr::KEY_SPACE;        // barre espace

                // add camera
                this->camera =
                    smgr->addCameraSceneNodeFPS(       // ajout de la camera FPS
                        0,                                     // pas de noeud parent
                        100.0f,                                // vitesse de rotation
                        0.1f,                                  // vitesse de deplacement
                        -1,                                    // pas de numero d'ID
                        keyMap,                                // on change la keymap
                        5                                      // avec une taille de 5
                    );
                camera->setPosition(core::vector3df(0,0,30)/*core::vector3df(2700*2,255*2,2600*2)*/);
                camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                camera->setFarValue(42000.0f);

                // disable mouse cursor
                device->getCursorControl()->setVisible(false);
            }
    };
} // graphique

#endif

