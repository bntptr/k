#ifndef IACTIONKEY_W_H
#define IACTIONKEY_W_H

#include "IKey.h"

#include "../../Selector/ISelectorService.h"

namespace graphique
{
    class KeyW : public IKey
    {
        public:
            KeyW(){};
            virtual ~KeyW(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                ISelectorService* selector = view->getSelector();
                selector->oneEventSelectorLeft(EACTIONEVENT_DEPLACE_X);
                return 0;
            }
    };
} // graphique

#endif

