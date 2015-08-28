#ifndef VIEW_EMIE_LMOUSE_PRESSED_DOWN_H
#define VIEW_EMIE_LMOUSE_PRESSED_DOWN_H

#include "IEmie.h"

namespace graphique
{
    class EmieLMousePressedDown : public IEmie
    {
        public:
            EmieLMousePressedDown(){};
            virtual ~EmieLMousePressedDown(){};

            int execute(IView *view) {
                view->getCursorService()->getLeft()->down();
                        /*MouseState.LeftButtonDown = true;
                        cursor->setCgDown();
                        cursor->run();*/
                return 0;
            }
    };
} // graphique

#endif

