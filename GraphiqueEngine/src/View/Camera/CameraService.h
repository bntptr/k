#ifndef CAMERA_SERVICE_H
#define CAMERA_SERVICE_H

#include "Camera.h"
#include "ICameraService.h"
#include "CameraFactory.h"

namespace graphique
{
    class CameraService : public ICameraService
    {
        protected:
            ICameraService *thisInstance;
            ICamera *camera;

        public:
            CameraService(irr::IrrlichtDevice *device, ICursorEntity *cursor){
                this->thisInstance = this;
                this->camera = CameraFactory::createEntity(device, cursor);
            };
            ~CameraService(){};

            scene::ICameraSceneNode* getCamera() {
                return this->camera->getCamera();
            }

            bool build() {
                return this->camera->build();
            }

            bool draw() {
                return this->camera->draw();
            }
    };
} // business

#endif


