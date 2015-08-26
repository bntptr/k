#ifndef VIEW_MODE_EDITOR_H
#define VIEW_MODE_EDITOR_H

#include "IAction.h"

namespace graphique
{
    class ModeEditor : public IAction
    {
        public:
            ModeEditor(){};
            virtual ~ModeEditor(){};

            int execute(IView *view) {
                return -1;
            }
    };
} // graphique

#endif





