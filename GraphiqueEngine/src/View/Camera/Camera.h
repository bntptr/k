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
            ICursorEntity* cursor;
        public:
            Camera(irr::IrrlichtDevice *device, ICursorEntity *cursor){
                this->device = device;
                this->cursor = cursor;
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
                    smgr->addCameraSceneNodeFPS(0,100.0f,1.2f/*0.1f*/);

                camera->setPosition(core::vector3df(0,0,30)/*core::vector3df(2700*2,255*2,2600*2)*/);
                camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                camera->setFarValue(42000.0f);

                if (this->cursor->getSelector())
                {
                    scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
                        this->cursor->getSelector(), camera, core::vector3df(30,50,30),
                        core::vector3df(0,-10,0), core::vector3df(0,30,0));
                    this->cursor->getSelector()->drop(); // As soon as we're done with the selector, drop it.
                    camera->addAnimator(anim);
                    anim->drop();  // And likewise, drop the animator when we're done referring to it.
                }
            }
    };
} // graphique

#endif
