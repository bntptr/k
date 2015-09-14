#ifndef VIEW3D_FPS_CAMERA_FACTORY_H
#define VIEW3D_FPS_CAMERA_FACTORY_H

#include "FPS.h"
#include "../../Cursor/ICursorService.h"

namespace graphique
{
    class CameraFPSFactory
    {
        public:
            static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new CameraFPS(device, cursor);
            }
    };
} // graphique

#endif

