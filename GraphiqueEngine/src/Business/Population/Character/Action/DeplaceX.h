#ifndef BUSINESS_CHARACTER_DEPLACEX_H
#define BUSINESS_CHARACTER_DEPLACEX_H

#include "IAction.h"

namespace business
{
    namespace character
    {
        class DeplaceX : public IAction
        {
            public:
                DeplaceX(){};
                virtual ~DeplaceX(){};

                int execute(ICharacterEntity *character) {
                    float newX = character->getPosition().getX() + 10;
                    character->getPosition().setX(newX);
std::cout << "character " << character->getPosition().getX() << std::endl;;
                }
        };
    }
} // business

#endif



