#ifndef BUSINESS_CHARACTER_DEPLACE_Y_H
#define BUSINESS_CHARACTER_DEPLACE_Y_H

#include "IAction.h"

namespace business
{
    namespace character
    {
        class DeplaceY : public IAction
        {
            public:
                DeplaceY(){};
                virtual ~DeplaceY(){};

                int execute(ICharacterEntity *character) {
                    Vector3d newPosition = character->getPosition();
                    float newY = newPosition.getY() + 1;
                    newPosition.setY(newY);
                    character->setPosition(newPosition);
                }
        };
    }
} // business

#endif




