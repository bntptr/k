#ifndef BUSINESSENTITY_H
#define BUSINESSENTITY_H

#include "IGroundEntity.h"
#include "ISkyEntity.h"
#include "IPopulationEntity.h"
#include "IPlayerEntity.h"

namespace graphique
{
    class BusinessEntity
    {
        public:
            IGroundEntity* getGround();
            ISkyEntity* getSky();
            IPopulationEntity* getPopulation();
            IPlayerEntity* getPlayer();

            BusinessEntity* setGround(IGroundEntity *ground);
            BusinessEntity* setSky(ISkyEntity *sky);
            BusinessEntity* setPopulation(IPopulationEntity *population);
            BusinessEntity* setPlayer(IPlayerEntity *player);

        protected:
            IGroundEntity *ground;
            ISkyEntity *sky;
            IPopulationEntity *population;
            IPlayerEntity *player;
    };

    IGroundEntity* BusinessEntity::getGround()
    {
        return this->ground;
    }

    ISkyEntity* BusinessEntity::getSky()
    {
        return this->sky;
    }

    IPopulationEntity* BusinessEntity::getPopulation()
    {
        return this->population;
    }

    IPlayerEntity* BusinessEntity::getPlayer()
    {
        return this->player;
    }

    BusinessEntity* BusinessEntity::setGround(IGroundEntity *ground)
    {
        this->ground = ground;
        return this;
    }

    BusinessEntity* BusinessEntity::setSky(ISkyEntity *sky)
    {
        this->sky = sky;
        return this;
    }

    BusinessEntity* BusinessEntity::setPopulation(IPopulationEntity *population)
    {
        this->population = population;
        return this;
    }

    BusinessEntity* BusinessEntity::setPlayer(IPlayerEntity *player)
    {
        this->player = player;
        return this;
    }
} // graphique

#endif
