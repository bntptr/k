#ifndef EMIE_RMOUSE_LEFT_UP_H
#define EMIE_RMOUSE_LEFT_UP_H

#include "IEmie.h"

namespace graphique
{
    class EmieRMouseLeftUp : public IEmie
    {
        public:
            EmieRMouseLeftUp(){};
            virtual ~EmieRMouseLeftUp(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif



