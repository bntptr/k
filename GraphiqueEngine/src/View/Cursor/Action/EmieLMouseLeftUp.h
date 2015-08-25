#ifndef EMIE_LMOUSE_LEFT_UP_H
#define EMIE_LMOUSE_LEFT_UP_H

#include "IEmie.h"

namespace graphique
{
    class EmieLMouseLeftUp : public IEmie
    {
        public:
            EmieLMouseLeftUp(){};
            virtual ~EmieLMouseLeftUp(){};

            int execute(IView *view) {
                std::cout << "LMouseLeftUp" << std::endl;
                view->getCursor()->getLeft()->up();
                view->getSelector()->selectLeft(view);
                        /*MouseState.LeftButtonDown = false;
                        cursor->setCgUp();
                        cursor->run();*/
                return 0;
            }
    };
} // graphique

#endif


