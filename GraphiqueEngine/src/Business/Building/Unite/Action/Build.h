#ifndef BUSINESS_BUILDING_UNIT_ACTION_BUILD_H
#define BUSINESS_BUILDING_UNIT_ACTION_BUILD_H

#include "IAction.h"

namespace business
{
    namespace building
    {
        class Build : public IAction
        {
            public:
                Build(){};
                virtual ~Build(){};

                int execute(IBuildingUnite *unite) {
                    Vector3d newPosition = unite->getPosition();
                    float newX = newPosition.getX() + 1;
                    newPosition.setX(newX);
                    unite->setPosition(newPosition);
                }
        };
    }
} // business

#endif



