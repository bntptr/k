#ifndef VIEW_CURSOR_SERVICE_FACTORY_H
#define VIEW_CURSOR_SERVICE_FACTORY_H

#include "CursorService.h"

namespace graphique
{
    class CursorServiceFactory
    {
        public:
            static ICursorService* createService(irr::IrrlichtDevice *device, IView *view) {
                return new CursorService(device, view);
            }
    };
} // graphique

#endif




