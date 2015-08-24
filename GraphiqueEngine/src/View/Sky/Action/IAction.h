#ifndef VIEW_SKY_IACTION_H
#define VIEW_SKY_IACTION_H

#include "../ISkyView.h"

namespace graphique
{
    namespace sky
    {
        class IAction
        {
            public:
                IAction(){};
                virtual ~IAction(){};

                virtual int execute(ISkyView *sky) {
                    return -1;
                };
        };
    } // sky
} // graphique

#endif


