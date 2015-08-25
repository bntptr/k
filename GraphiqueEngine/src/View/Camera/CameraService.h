#ifndef CAMERA_SERVICE_H
#define CAMERA_SERVICE_H

#include "Camera.h"
#include "ICameraService.h"

namespace graphique
{
    class CameraService : public ICameraService
    {
        protected:
            ICameraService* thisInstance;

        public:
            CameraService(){
                this->thisInstance = this;
            };
            ~CameraService(){};
    };
} // business

#endif


