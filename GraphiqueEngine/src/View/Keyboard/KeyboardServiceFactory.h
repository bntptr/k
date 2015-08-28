#ifndef VIEW_KEYBOARD_SERVICE_FACTORY_H
#define VIEW_KEYBOARD_SERVICE_FACTORY_H

#include "KeyboardService.h"

namespace graphique
{
    class KeyboardServiceFactory
    {
        public:
            static IKeyboardService* createService(IView *view) {
                return new KeyboardService(view);
            }
    };
} // graphique

#endif


