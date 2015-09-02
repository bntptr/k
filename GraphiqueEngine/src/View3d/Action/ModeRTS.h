#ifndef VIEW_MODE_RTS_H
#define VIEW_MODE_RTS_H

#include "../../View/Action/IAction.h"

namespace graphique
{
    class ModeRTS : public IAction
    {
        public:
            ModeRTS(){};
            virtual ~ModeRTS(){};

            int execute(IView *view) {
                ICameraService *camera = view->getCameraService();
                //camera->activeRTS();
                return 0;
            }
    };
} // graphique

#endif





