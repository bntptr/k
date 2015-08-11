#ifndef IACTIONKEYW_H
#define IACTIONKEYW_H

#include "IKey.h"

namespace graphique
{
    class KeyW : public IKey
    {
        public:
            KeyW(){};
            virtual ~KeyW(){};

            int execute(IView *view) {
                SelectorService* selector = view->getSelector();
                selector->oneEventSelectorLeft(EACTIONEVENT_DEPLACE_X);
            }
    };
} // graphique

#endif

