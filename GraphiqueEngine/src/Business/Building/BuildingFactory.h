#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "BuildingEntity.h"

namespace business
{
    class BuildingFactory
    {
        public:
            static IBuildingEntity* createEntity() {
                return new BuildingEntity();
            }
    };
} // business

#endif
