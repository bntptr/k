#ifndef VIEW_KEYBOARD_2D_SERVICE_FACTORY_H
#define VIEW_KEYBOARD_2D_SERVICE_FACTORY_H

#include "Keyboard2dService.h"

namespace graphique
{
    class Keyboard2dServiceFactory
    {
        public:
            static IKeyboardService* createService(IView *view) {
                return new Keyboard2dService(view);
            }
    };
} // graphique

#endif


