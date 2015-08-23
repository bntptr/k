#ifndef EMIE_RMOUSE_PRESSED_DOWN_H
#define EMIE_RMOUSE_PRESSED_DOWN_H

#include "IEmie.h"

namespace graphique
{
    class EmieRMousePressedDown : public IEmie
    {
        public:
            EmieRMousePressedDown(){};
            virtual ~EmieRMousePressedDown(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


