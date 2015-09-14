#ifndef VIEW_CURSOR_2D_SERVICE_FACTORY_H
#define VIEW_CURSOR_2D_SERVICE_FACTORY_H

#include "Cursor2dService.h"

namespace graphique
{
    class Cursor2dServiceFactory
    {
        public:
            static ICursorService* createService(irr::IrrlichtDevice *device, IView *view) {
                return new Cursor2dService(device, view);
            }
    };
} // graphique

#endif




