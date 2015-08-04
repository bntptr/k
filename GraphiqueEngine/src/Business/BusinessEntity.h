#ifndef BUSINESSENTITY_H
#define BUSINESSENTITY_H

#include "IBusinessEntity.h"

namespace graphique
{
    class BusinessEntity : public IBusinessEntity
    {
        public:
            BusinessEntity(){
                this->thisInterface = this;
            };
            ~BusinessEntity(){};
            IGroundEntity* getGround();
            ISkyEntity* getSky();
            IPopulationEntity* getPopulation();
            IPlayerEntity* getPlayer();

            IBusinessEntity* setGround(IGroundEntity *ground);
            IBusinessEntity* setSky(ISkyEntity *sky);
            IBusinessEntity* setPopulation(IPopulationEntity *population);
            IBusinessEntity* setPlayer(IPlayerEntity *player);

        protected:
            IGroundEntity *ground;
            ISkyEntity *sky;
            IPopulationEntity *population;
            IPlayerEntity *player;

            IBusinessEntity *thisInterface;
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

    IBusinessEntity* BusinessEntity::setGround(IGroundEntity *ground)
    {
        this->ground = ground;
        return thisInterface;
    }

    IBusinessEntity* BusinessEntity::setSky(ISkyEntity *sky)
    {
        this->sky = sky;
        return thisInterface;
    }

    IBusinessEntity* BusinessEntity::setPopulation(IPopulationEntity *population)
    {
        this->population = population;
        return thisInterface;
    }

    IBusinessEntity* BusinessEntity::setPlayer(IPlayerEntity *player)
    {
        this->player = player;
        return thisInterface;
    }
} // graphique

#endif
