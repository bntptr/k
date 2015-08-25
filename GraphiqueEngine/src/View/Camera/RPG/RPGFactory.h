#ifndef FPS_CAMERA_FACTORY_H
#define FPS_CAMERA_FACTORY_H

#include "FPS.h"
#include "../../Cursor/ICursorEntity.h"

namespace graphique
{
    class FPSFactory
    {
    public:
        static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorEntity *cursor) {
            return new FPS(device, cursor);
        }
    };
} // graphique

#endif

