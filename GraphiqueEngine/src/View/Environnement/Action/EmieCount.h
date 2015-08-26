#ifndef EMIE_COUNT_H
#define EMIE_COUNT_H

#include "IEmie.h"

namespace graphique
{
    class EmieCount : public IEmie
    {
        public:
            EmieCount(){};
            virtual ~EmieCount(){};

            int execute(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


