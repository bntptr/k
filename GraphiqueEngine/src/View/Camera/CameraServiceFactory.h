#ifndef VIEW_CAMERA_SERVICE_FACTORY_H
#define VIEW_CAMERA_SERVICE_FACTORY_H

#include "CameraService.h"

namespace graphique
{
    class CameraServiceFactory
    {
        public:
            static ICameraService* createService(irr::IrrlichtDevice *device, ICursorEntity *cursor) {
                return new CameraService(device, cursor);
            }
    };
} // graphique

#endif

