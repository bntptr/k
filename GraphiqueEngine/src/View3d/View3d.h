#ifndef VIEW_3D_H
#define VIEW_3D_H

#include <irrlicht.h>

#include "../View/View.h"
#include "Action/Actions.h"
//#include "Cursor/Cursor3dServiceFactory.h"
//#include "Keyboard/Keyboard3dServiceFactory.h"
//#include "Camera/Camera3dServiceFactory.h"
//#include "Environnement/Environnement3dServiceFactory.h"

namespace graphique
{
    class View3d : public View
    {
        public:
            View3d(TMap<EVIEW, IAction>* keyMap) : View(keyMap) {}
            View3d(TMap<EVIEW, IAction>* keyMap, IView *view) : View(keyMap, view){
                this->mode = EVIEW_MODE_EDITOR;
            }
            ~View3d(){};

            /**
             * Construction de tous les éléments de la scène graphique
             */
            /*int build(business::BusinessInterface *business) {
                std::cout <<"build view3d !" << std::endl;
                business::IBusinessEntity *entity = business->loadBusinessEntity();

                this->cursor = Cursor3dServiceFactory::createService(this->device, this);

                this->keyboard = Keyboard3dServiceFactory::createService(this);

                this->environnement = Environnement3dServiceFactory::createService(this->device);
                this->environnement->build();

                this->camera = Camera3dServiceFactory::createService(this->device, this->cursor);
                this->camera->build();

                this->cursor->setCameraService(this->camera);

                this->buildGame(business);
                return 0;
            }*/
    };
} // graphique

#endif

