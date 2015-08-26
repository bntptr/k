#ifndef VIEW_MODE_RTS_H
#define VIEW_MODE_RTS_H

#include "IAction.h"

namespace graphique
{
    class ModeRTS : public IAction
    {
        public:
            ModeRTS(){};
            virtual ~ModeRTS(){};

            int execute(IView *view) {
                return -1;
            }
    };
} // graphique

#endif





