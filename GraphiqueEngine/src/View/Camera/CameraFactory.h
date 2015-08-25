#ifndef CAMERA_FACTORY_H
#define CAMERA_FACTORY_H

#include "Camera.h"
#include "../Cursor/ICursorService.h"

namespace graphique
{
    class CameraFactory
    {
        public:
            static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new Camera(device, cursor);
            }
    };
} // graphique

#endif
