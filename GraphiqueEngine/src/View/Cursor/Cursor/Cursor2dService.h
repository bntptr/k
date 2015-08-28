#ifndef VIEW_CURSOR_2D_SERVICE_H
#define VIEW_CURSOR_2D_SERVICE_H

#include "../CursorService.h"
#include "Cursor2dFactory.h"

namespace graphique
{
    class Cursor2dService : public CursorService
    {
        public:
            Cursor2dService(irr::IrrlichtDevice *device, IView *view) : CursorService(/*device, view*/){
                this->thisInstance = this;
                this->cursor = Cursor2dFactory::createEntity(device, view);
            };
            ~Cursor2dService(){};
    };
} // business

#endif



