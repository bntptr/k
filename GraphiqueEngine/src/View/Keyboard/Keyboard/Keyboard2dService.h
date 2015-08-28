#ifndef VIEW_KEYBOARD_2D_SERVICE_H
#define VIEW_KEYBOARD_2D_SERVICE_H

#include "../KeyboardService.h"
#include "Keyboard2dFactory.h"

namespace graphique
{
    class Keyboard2dService : public KeyboardService
    {
        public:
            Keyboard2dService(IView *view) : KeyboardService(view){
                this->thisInstance = this;
                this->keyboard = Keyboard2dFactory::createEntity(view);
            };
            ~Keyboard2dService(){};
    };
} // business

#endif




