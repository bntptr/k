#ifndef TWO_D_CAMERA_FACTORY_H
#define TWO_D_CAMERA_FACTORY_H

#include "2D.h"
#include "../../View/Cursor/ICursorService.h"

namespace graphique
{
    class Camera2dFactory
    {
        public:
            static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new Camera2D(device, cursor);
            }
    };
} // graphique

#endif

