#ifndef VIEW_2D_H
#define VIEW_2D_H

#include <irrlicht.h>

#include "../View.h"
#include "../Cursor/Cursor/Cursor2dServiceFactory.h"
#include "../Keyboard/Keyboard/Keyboard2dServiceFactory.h"
#include "../Camera/Camera/Camera2dServiceFactory.h"
#include "../Environnement/Environnement/Environnement2dServiceFactory.h"

namespace graphique
{
    class View2d : public View
    {
        public:
            View2d(TMap<EVIEW, IAction>* keyMap) : View(keyMap) {}
            ~View2d(){};

            /**
             * Construction de tous les éléments de la scène graphique
             */
            int build(business::BusinessInterface *business) {
                std::cout <<"build view2d !" << std::endl;
                business::IBusinessEntity *entity = business->loadBusinessEntity();

                this->cursor = Cursor2dServiceFactory::createService(this->device, this);
                this->cursor->build();

                this->keyboard = Keyboard2dServiceFactory::createService(this);

                this->environnement = Environnement2dServiceFactory::createService(this->device);
                this->environnement->build();

                this->camera = Camera2dServiceFactory::createService(this->device, this->cursor);
                this->camera->build();

                this->cursor->setCameraService(this->camera);

                this->buildGame(business);
                return 0;
            }
    };
} // graphique

#endif
