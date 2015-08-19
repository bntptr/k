#ifndef IEMIE_H
#define IEMIE_H

#include "../../IView.h"
#include "../../../Business/Event/EActionEvent.h"

namespace graphique
{
    class IEmie
    {
        public:
            IEmie(){};
            virtual ~IEmie(){};

            virtual int execute(IView *view)=0;
    };
} // graphique

#endif
