#ifndef IACTIONKEY_X_H
#define IACTIONKEY_X_H

#include "IKey.h"

#include "../../Selector/ISelectorService.h"

namespace graphique
{
    class KeyX : public IKey
    {
        public:
            KeyX(){};
            virtual ~KeyX(){};

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

