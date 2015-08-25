#ifndef VIEW_IACTION_H
#define VIEW_IACTION_H

#include "../IView.h"

namespace graphique
{
    class IAction
    {
        public:
            IAction(){};
            virtual ~IAction(){};

            virtual int execute(IView *view) {
                return -1;
            }
    };
} // graphique

#endif


