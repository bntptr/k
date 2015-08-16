#ifndef CURSOR_FACTORY_H
#define CURSOR_FACTORY_H

#include "CursorEntity.h"

namespace graphique
{
    class CursorFactory
    {
    public:
        static ICursorEntity* createEntity(irr::IrrlichtDevice *device) {
            return new CursorEntity(device);
        }
    };
} // graphique

#endif



