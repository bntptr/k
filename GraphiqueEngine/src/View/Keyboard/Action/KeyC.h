#ifndef IACTIONKEY_C_H
#define IACTIONKEY_C_H

#include "IKey.h"

#include "../../Selector/ISelectorService.h"

namespace graphique
{
    class KeyC : public IKey
    {
        public:
            KeyC(){};
            virtual ~KeyC(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                ISelectorService* selector = view->getSelector();
                selector->oneEventSelectorLeft(EACTIONEVENT_DEPLACE_Z);
                return 0;
            }
    };
} // graphique

#endif

