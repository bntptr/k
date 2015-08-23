#ifndef EMIE_DOUBLE_CLICK_H
#define EMIE_DOUBLE_CLICK_H

#include "IEmie.h"

namespace graphique
{
    class EmieDoubleClick : public IEmie
    {
        public:
            EmieDoubleClick(){};
            virtual ~EmieDoubleClick(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


