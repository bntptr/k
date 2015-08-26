#ifndef CAMERA_SERVICE_H
#define CAMERA_SERVICE_H

#include "Camera.h"
#include "ICameraService.h"
#include "CameraFactory.h"
#include "Camera/Camera2dFactory.h"
#include "Camera/CameraFPSFactory.h"
#include "Camera/CameraRTSFactory.h"
#include "Camera/CameraRPGFactory.h"
#include "Camera/CameraEditorFactory.h"

namespace graphique
{
    class CameraService : public ICameraService
    {
        protected:
            ICameraService *thisInstance;
            ICamera *camera;

            irr::IrrlichtDevice *device;
            ICursorService *cursor;

        public:
            CameraService(irr::IrrlichtDevice *device, ICursorService *cursor){
                this->thisInstance = this;
                this->camera = CameraFactory::createEntity(device, cursor);
                this->device = device;
                this->cursor = cursor;
            };
            ~CameraService(){};

            scene::ICameraSceneNode* getCameraSceneNode() {
                return this->camera->getCameraSceneNode();
            }

            bool build() {
                return this->camera->build();
            }

            bool draw() {
                return this->camera->draw();
            }

            bool active2d() {
                this->camera = Camera2dFactory::createEntity(this->device, this->cursor);
                this->build();
                return true;
            }

            bool activeFPS() {
                this->camera = CameraFPSFactory::createEntity(this->device, this->cursor);
                this->build();
                return true;
            }

            bool activeRTS() {
                this->camera = CameraRTSFactory::createEntity(this->device, this->cursor);
                this->build();
                return true;
            }

            bool activeRPG() {
                this->camera = CameraRPGFactory::createEntity(this->device, this->cursor);
                this->build();
                return true;
            }

            bool activeEditor() {
                this->camera = CameraEditorFactory::createEntity(this->device, this->cursor);
                this->build();
                return true;
            }
    };
} // business

#endif


