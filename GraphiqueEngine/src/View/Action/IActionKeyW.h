#ifndef IACTIONKEYW_H
#define IACTIONKEYW_H

#include "IActionKey.h"

namespace graphique
{
    class IActionKeyW : public IActionKey
    {
        public:
            IActionKeyW(){};
            virtual ~IActionKeyW(){};

            int execute(IView *view) {
                SelectorService* selector = view->getSelector();
                selector->oneEventSelectorLeft(EACTIONEVENT_DEPLACE_X);
            }
    };
} // graphique

#endif

