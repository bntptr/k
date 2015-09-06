#ifndef BUSINESS_FACTORY_H
#define BUSINESS_FACTORY_H

#include "BusinessEntity.h"

#include "Ground/GroundFactory.h"
#include "Sky/SkyFactory.h"
#include "Population/PopulationFactory.h"
#include "Player/PlayerFactory.h"

namespace business
{
    class BusinessFactory
    {
        public:
            static IBusinessEntity* createEntity() {
                IGroundEntity *ground = GroundFactory::createEntity(
                    Vector3d(0, 0, 0),
                    Vector3d(0, 0, 0),
                    Vector3d(40, 4.4, 40),
                    ETEXTURE_TERRAIN_DEFAULT,
                    EMESH_TERRAIN_DEFAULT
                );
                ISkyEntity *sky = SkyFactory::createEntity(
                    ETEXTURE_SKY_DOME_DEFAULT,
                    ETEXTURE_SKY_BOX_DEFAULT_UP,
                    ETEXTURE_SKY_BOX_DEFAULT_DN,
                    ETEXTURE_SKY_BOX_DEFAULT_LF,
                    ETEXTURE_SKY_BOX_DEFAULT_RT,
                    ETEXTURE_SKY_BOX_DEFAULT_FT,
                    ETEXTURE_SKY_BOX_DEFAULT_BK
                );
                IPopulationEntity *population = PopulationFactory::createEntity();
                IPlayerEntity *player = PlayerFactory::createEntity();
                IBusinessEntity* entity = new BusinessEntity();
                entity->setGround(ground)
                    ->setSky(sky)
                    ->setPopulation(population)
                    ->setPlayer(player);
                return entity;
            }

            static IBusinessEntity* createEntity(
                IPlayerEntity *player,
                IGroundEntity *ground,
                ISkyEntity *sky,
                IPopulationEntity *population
            ) {
                IBusinessEntity* entity = new BusinessEntity();
                entity->setGround(ground)
                    ->setSky(sky)
                    ->setPopulation(population)
                    ->setPlayer(player);
                return entity;
            }
    };
} // business

#endif
