#ifndef VIEW_KEYBOARD_2D_SERVICE_H
#define VIEW_KEYBOARD_2D_SERVICE_H

#include "../KeyboardService.h"
#include "../KeyboardFactory.h"

namespace graphique
{
    class Keyboard2dService : public KeyboardService
    {
        public:
            Keyboard2dService(IView *view) : Keyboard2dService(view){
                //this->thisInstance = this;
                //this->keyboard = KeyboardFactory::createEntity(view);
            };
            ~Keyboard2dService(){};
    };
} // business

#endif




