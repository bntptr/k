#ifndef FPS_CAMERA_FACTORY_H
#define FPS_CAMERA_FACTORY_H

#include "FPS.h"
#include "../../Cursor/ICursorService.h"

namespace graphique
{
    class FPSFactory
    {
    public:
        static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
            return new FPS(device, cursor);
        }
    };
} // graphique

#endif

