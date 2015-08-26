#ifndef VIEW_MODE_2D_H
#define VIEW_MODE_2D_H

#include "IAction.h"

namespace graphique
{
    class Mode2d : public IAction
    {
        public:
            Mode2d(){};
            virtual ~Mode2d(){};

            int execute(IView *view) {
                return -1;
            }
    };
} // graphique

#endif





