#ifndef VIEW_CHARACTER_ACTION_H
#define VIEW_CHARACTER_ACTION_H

#include "IAction.h"

namespace graphique
{
    class Action : public IAction
    {
        public:
            Action(){};
            virtual ~Action(){};

            int execute(ICharacter *character) {
                //SelectorService* selector = character->getSelector();
                //selector->oneEventSelectorLeft(EACTIONEVENT_DEPLACE_X);
            }
    };
} // graphique

#endif

