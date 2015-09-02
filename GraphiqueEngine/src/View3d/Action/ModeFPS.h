#ifndef VIEW_MODE_FPS_H
#define VIEW_MODE_FPS_H

#include "../../View/Action/IAction.h"

namespace graphique
{
    class ModeFPS : public IAction
    {
        public:
            ModeFPS(){};
            virtual ~ModeFPS(){};

            int execute(IView *view) {
                ICameraService *camera = view->getCameraService();
                IPopulationService *population = view->getPopulationService();
                IObjectView *firstObjectView = view->getSelector()->getFirstObjectViewSelected();
                //camera->activeFPS();
                //population->activeFPS(firstObjectView);
                return 0;
            }
    };
} // graphique

#endif





