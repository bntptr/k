#ifndef FPS_CAMERA_FACTORY_H
#define FPS_CAMERA_FACTORY_H

#include "FPS.h"

namespace graphique
{
    class FPSFactory
    {
    public:
        static ICamera* createEntity(irr::IrrlichtDevice *device) {
            return new FPS(device);
        }
    };
} // graphique

#endif

