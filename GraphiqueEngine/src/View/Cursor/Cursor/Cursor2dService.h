#ifndef VIEW_CURSOR_2D_SERVICE_H
#define VIEW_CURSOR_2D_SERVICE_H

#include "../CursorService.h"

namespace graphique
{
    class Cursor2dService : public CursorService
    {
        public:
            Cursor2dService(irr::IrrlichtDevice *device, IView *view) : Cursor2dService(device, view){
                //this->thisInstance = this;
                //this->cursor = CursorFactory::createEntity(device, view);
            };
            ~Cursor2dService(){};
    };
} // business

#endif



