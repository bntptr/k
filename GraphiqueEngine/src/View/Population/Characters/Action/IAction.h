#ifndef VIEW_CHARACTER_IACTION_H
#define VIEW_CHARACTER_IACTION_H

#include "../ICharacter.h"

namespace graphique
{
    namespace character
    {
        class IAction
        {
            public:
                IAction(){};
                virtual ~IAction(){};

                virtual int execute(ICharacter *character)=0;
        };
    } // character
} // graphique

#endif


