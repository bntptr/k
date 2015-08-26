#ifndef VIEW_MODE_FPS_H
#define VIEW_MODE_FPS_H

#include "IAction.h"

namespace graphique
{
    class ModeFPS : public IAction
    {
        public:
            ModeFPS(){};
            virtual ~ModeFPS(){};

            int execute(IView *view) {
                ICameraService *camera = view->getCameraService();
                camera->activeFPS();
                return -1;
            }
    };
} // graphique

#endif





