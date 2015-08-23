#ifndef EMIE_LMOUSE_PRESSED_DOWN_H
#define EMIE_LMOUSE_PRESSED_DOWN_H

#include "IEmie.h"

namespace graphique
{
    class EmieLMousePressedDown : public IEmie
    {
        public:
            EmieLMousePressedDown(){};
            virtual ~EmieLMousePressedDown(){};

            int execute(IView *view) {
                return 0;
            }
    };
} // graphique

#endif

