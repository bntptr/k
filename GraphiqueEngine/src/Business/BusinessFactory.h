#ifndef BUSINESS_FACTORY_H
#define BUSINESS_FACTORY_H

#include "BusinessEntity.h"

namespace graphique
{
    class BusinessFactory
    {
    public:
        static IBusinessEntity* createEntity(
            IPlayerEntity *player,
            IGroundEntity *ground,
            ISkyEntity *sky,
            IPopulationEntity *population
        ) {
            return new BusinessEntity();
        }
    };
} // graphique

#endif
