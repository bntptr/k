#ifndef EMIE_RMOUSE_LEFT_UP_H
#define EMIE_RMOUSE_LEFT_UP_H

#include "IEmie.h"

namespace graphique
{
    class EmieRMouseLeftUp : public IEmie
    {
        public:
            EmieRMouseLeftUp(){};
            virtual ~EmieRMouseLeftUp(){};

            int execute(IView *view) {
                view->getCursorService()->getRight()->up();
                                    /*MouseState.LeftButtonDown = false;
                        cursor->setCdUp();
                        cursor->run();*/
                return 0;
            }
    };
} // graphique

#endif



