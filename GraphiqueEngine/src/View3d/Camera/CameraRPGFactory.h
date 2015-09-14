#ifndef VIEW3D_RPG_CAMERA_FACTORY_H
#define VIEW3D_RPG_CAMERA_FACTORY_H

#include "RPG.h"
#include "../../Cursor/ICursorService.h"

namespace graphique
{
    class CameraRPGFactory
    {
        public:
            static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new CameraRPG(device, cursor);
            }
    };
} // graphique

#endif

