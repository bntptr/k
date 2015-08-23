#ifndef EMIE_MOUSE_MOVED_H
#define EMIE_MOUSE_MOVED_H

#include "IEmie.h"

namespace graphique
{
    class EmieMouseMoved : public IEmie
    {
        public:
            EmieMouseMoved(){};
            virtual ~EmieMouseMoved(){};

            int execute(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


