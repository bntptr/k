#ifndef IACTIONKEY_H
#define IACTIONKEY_H

#include "../IView.h"
#include "EActionEvent.h"

namespace graphique
{
    class IKey
    {
        public:
            IKey(){};
            virtual ~IKey(){};

            virtual int execute(IView *view)=0;
    };
} // graphique

#endif
