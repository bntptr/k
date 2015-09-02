#ifndef RTS_CAMERA_FACTORY_H
#define RTS_CAMERA_FACTORY_H

#include "RTS.h"
#include "../../Cursor/ICursorService.h"

namespace graphique
{
    class CameraRTSFactory
    {
        public:
            static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new CameraRTS(device, cursor);
            }
    };
} // graphique

#endif

