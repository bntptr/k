#ifndef VIEW_CAMERA_2D_SERVICE_FACTORY_H
#define VIEW_CAMERA_2D_SERVICE_FACTORY_H

#include "Camera2dService.h"

namespace graphique
{
    class Camera2dServiceFactory
    {
        public:
            static ICameraService* createService(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new Camera2dService(device, cursor);
            }
    };
} // graphique

#endif

