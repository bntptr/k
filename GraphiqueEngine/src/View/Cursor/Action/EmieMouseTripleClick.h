#ifndef EMIE_MOUSE_TRIPLE_CLICK_H
#define EMIE_MOUSE_TRIPLE_CLICK_H

#include "IEmie.h"

namespace graphique
{
    class EmieMouseTripleClick : public IEmie
    {
        public:
            EmieMouseTripleClick(){};
            virtual ~EmieMouseTripleClick(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


