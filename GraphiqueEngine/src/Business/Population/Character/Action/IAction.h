#ifndef BUSINESS_CHARACTER_IACTION_H
#define BUSINESS_CHARACTER_IACTION_H

#include "../ICharacterEntity.h"

namespace business
{
    namespace character
    {
        class IAction
        {
            public:
                IAction(){};
                virtual ~IAction(){};

                virtual int execute(ICharacterEntity *character) {
                    return -1;
                }
        };
    } // character
} // business

#endif



