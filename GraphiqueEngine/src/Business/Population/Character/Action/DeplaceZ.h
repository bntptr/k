#ifndef BUSINESS_CHARACTER_DEPLACE_Z_H
#define BUSINESS_CHARACTER_DEPLACE_Z_H

#include "IAction.h"

namespace business
{
    namespace character
    {
        class DeplaceZ : public IAction
        {
            public:
                DeplaceZ(){};
                virtual ~DeplaceZ(){};

                int execute(ICharacterEntity *character) {
                    Vector3d newPosition = character->getPosition();
                    float newZ = newPosition.getZ() + 1;
                    newPosition.setZ(newZ);
                    character->setPosition(newPosition);
                }
        };
    }
} // business

#endif



