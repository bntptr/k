#ifndef IACTIONKEY_V_H
#define IACTIONKEY_V_H

#include "IKey.h"

#include "../../Selector/ISelectorService.h"

namespace graphique
{
    class KeyV : public IKey
    {
        public:
            KeyV(){};
            virtual ~KeyV(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                ISelectorService* selector = view->getSelector();
                selector->onEventSelectorLeft(EACTIONEVENT_DEPLACE_Z);
                return 0;
            }
    };
} // graphique

#endif

