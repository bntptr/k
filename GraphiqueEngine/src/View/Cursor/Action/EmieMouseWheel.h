#ifndef EMIE_MOUSE_WHEEL_H
#define EMIE_MOUSE_WHEEL_H

#include "IEmie.h"

namespace graphique
{
    class EmieMouseWheel : public IEmie
    {
        public:
            EmieMouseWheel(){};
            virtual ~EmieMouseWheel(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif

