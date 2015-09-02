#ifndef VIEW_MODE_RPG_H
#define VIEW_MODE_RPG_H

#include "IAction.h"

namespace graphique
{
    class ModeRPG : public IAction
    {
        public:
            ModeRPG(){};
            virtual ~ModeRPG(){};

            int execute(IView *view) {
                ICameraService *camera = view->getCameraService();
                camera->activeRPG();
                return -1;
            }
    };
} // graphique

#endif





