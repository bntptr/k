#ifndef VIEW_EMIE_MOUSE_MOVED_H
#define VIEW_EMIE_MOUSE_MOVED_H

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


