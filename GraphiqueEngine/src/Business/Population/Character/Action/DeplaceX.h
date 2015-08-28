#ifndef BUSINESS_CHARACTER_DEPLACE_X_H
#define BUSINESS_CHARACTER_DEPLACE_X_H

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
                    Vector3d newPosition = character->getPosition();
                    float newX = newPosition.getX() + 1;
                    newPosition.setX(newX);
                    character->setPosition(newPosition);
                }
        };
    }
} // business

#endif



