#ifndef VIEW_CLOSE_WINDOWS_H
#define VIEW_CLOSE_WINDOWS_H

#include "IAction.h"

namespace graphique
{
    class CloseWindows : public IAction
    {
        public:
            CloseWindows(){};
            virtual ~CloseWindows(){};

            int execute(IView *view) {
                view->exit();
                return 0;
            }
    };
} // graphique

#endif




