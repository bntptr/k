#ifndef CAMERA_2D_SERVICE_H
#define CAMERA_2D_SERVICE_H

#include "../../View/Camera/CameraService.h"
#include "Camera2dFactory.h"

namespace graphique
{
    class Camera2dService : public CameraService
    {
        protected:
            ICamera *camera2d;
        public:
            Camera2dService(irr::IrrlichtDevice *device, ICursorService *cursor){
                this->thisInstance = this;
                this->device = device;
                this->cursor = cursor;
                this->camera = Camera2dFactory::createEntity(this->device, this->cursor);
            };
            ~Camera2dService(){};


            bool build() {
                return this->camera->build();
            }

            /*bool draw(ITerrainService *terrain, IPopulationService *population) {
                return this->camera->draw(terrain, population);
            }*/
    };
} // business

#endif


