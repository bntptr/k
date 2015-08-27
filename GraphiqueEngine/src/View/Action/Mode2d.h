#ifndef VIEW_MODE_2D_H
#define VIEW_MODE_2D_H

#include "IAction.h"
//#include "../View/View2dFactory.h"

namespace graphique
{
    class Mode2d : public IAction
    {
        public:
            Mode2d(){};
            virtual ~Mode2d(){};

            int execute(IView *view) {
                view->exit();
                view->drop();
                //view = View2dFactory::createEntity();
                //ICameraService *camera = view->getCameraService();
                //camera->active2d();
                return -1;
            }
    };
} // graphique

#endif





