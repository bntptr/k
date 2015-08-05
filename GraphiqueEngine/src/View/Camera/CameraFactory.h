#ifndef CAMERA_FACTORY_H
#define CAMERA_FACTORY_H

#include "Camera.h"

namespace graphique
{
    class CameraFactory
    {
    public:
        static ICamera* createEntity(irr::IrrlichtDevice *device) {
            return new Camera(device);
        }
    };
} // graphique

#endif
