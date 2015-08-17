#ifndef BUSINESSENTITY_H
#define BUSINESSENTITY_H

#include "IBusinessEntity.h"

namespace business
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
            IBuildingEntity* getBuilding();
            IPlayerEntity* getPlayer();

            IBusinessEntity* setGround(IGroundEntity *ground);
            IBusinessEntity* setSky(ISkyEntity *sky);
            IBusinessEntity* setPopulation(IPopulationEntity *population);
            IBusinessEntity* setBuilding(IBuildingEntity *building);
            IBusinessEntity* setPlayer(IPlayerEntity *player);

        protected:
            IGroundEntity *ground;
            ISkyEntity *sky;
            IPopulationEntity *population;
            IBuildingEntity *building;
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

    IBuildingEntity* BusinessEntity::getBuilding()
    {
        return this->building;
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

    IBusinessEntity* BusinessEntity::setBuilding(IBuildingEntity *building)
    {
        this->building = building;
        return thisInterface;
    }

    IBusinessEntity* BusinessEntity::setPlayer(IPlayerEntity *player)
    {
        this->player = player;
        return thisInterface;
    }
} // business

#endif
