#ifndef VIEW_CAMERA_3D_SERVICE_FACTORY_H
#define VIEW_CAMERA_3D_SERVICE_FACTORY_H

#include "Camera3dService.h"

namespace graphique
{
    class Camera3dServiceFactory
    {
        public:
            static ICameraService* createService(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new Camera3dService(device, cursor);
            }
    };
} // graphique

#endif

