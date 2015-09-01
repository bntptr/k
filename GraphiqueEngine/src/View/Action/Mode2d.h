#ifndef VIEW_MODE_2D_H
#define VIEW_MODE_2D_H

#include "IAction.h"
#include "../../Action/EGraphique.h"
//#include "../View/View2dFactory.h"

namespace graphique
{
    class Mode2d : public IAction
    {
        public:
            Mode2d(){};
            virtual ~Mode2d(){};

            int execute(IView *view) {
                view->exit(EGRAPHIQUE_VIEW_2D);
                return 0;
            }
    };
} // graphique

#endif





