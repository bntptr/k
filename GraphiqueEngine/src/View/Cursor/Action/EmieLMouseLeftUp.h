#ifndef VIEW_EMIE_LMOUSE_LEFT_UP_H
#define VIEW_EMIE_LMOUSE_LEFT_UP_H

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
                view->getCursorService()->getLeft()->up();
                view->getSelector()->selectLeft(view);
                return 0;
            }
    };
} // graphique

#endif


