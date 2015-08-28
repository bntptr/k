#ifndef VIEW_EMIE_MOUSE_WHEEL_H
#define VIEW_EMIE_MOUSE_WHEEL_H

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
    };
} // graphique

#endif

