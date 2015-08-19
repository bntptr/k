#ifndef IACTIONKEY_S_H
#define IACTIONKEY_S_H

#include "IKey.h"
#include "../../Sky/ISkyView.h"

namespace graphique
{
    class KeyS : public IKey
    {
        public:
            KeyS(){};
            virtual ~KeyS(){};

            int execute(IView *view) {
                ISkyView* sky = view->getSky();
                sky->oneEvent(EACTIONEVENT_CHANGE_SKY);
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


