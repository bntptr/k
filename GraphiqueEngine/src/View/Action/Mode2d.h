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
                ICameraService *camera = view->getCameraService();
                camera->active2d();
                return -1;
            }
    };
} // graphique

#endif





