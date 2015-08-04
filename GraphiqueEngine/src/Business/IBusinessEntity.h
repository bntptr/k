#ifndef IBUSINESSENTITY_H
#define IBUSINESSENTITY_H

#include "IBusinessEntity.h"

#include "IGroundEntity.h"
#include "ISkyEntity.h"
#include "IPopulationEntity.h"
#include "IPlayerEntity.h"

namespace graphique
{
    class IBusinessEntity
    {
        public:
            virtual IGroundEntity* getGround()=0;
            virtual ISkyEntity* getSky()=0;
            virtual IPopulationEntity* getPopulation()=0;
            virtual IPlayerEntity* getPlayer()=0;

            virtual IBusinessEntity* setGround(IGroundEntity *ground)=0;
            virtual IBusinessEntity* setSky(ISkyEntity *sky)=0;
            virtual IBusinessEntity* setPopulation(IPopulationEntity *population)=0;
            virtual IBusinessEntity* setPlayer(IPlayerEntity *player)=0;
    };
} // graphique

#endif
