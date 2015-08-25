#ifndef VIEW_KEYBOARD_SERVICE_H
#define VIEW_KEYBOARD_SERVICE_H

#include "Action/Actions.h"
#include "IKeyboardService.h"

namespace graphique
{
    class KeyboardService : public IKeyboardService
    {
        protected:
            IKeyboardService* thisInstance;

        public:
            KeyboardService(){
                this->thisInstance = this;
            };
            ~KeyboardService(){};
    };
} // business

#endif




