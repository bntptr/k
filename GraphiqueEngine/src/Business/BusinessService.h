#ifndef BUSINESSSERVICE_H
#define BUSINESSSERVICE_H

#include "BusinessInterface.h"
#include "BusinessFactory.h"

#include "Ground/GroundFactory.h"
#include "Sky/SkyFactory.h"
#include "Population/PopulationFactory.h"
#include "Player/PlayerFactory.h"

namespace business
{
    class BusinessService : public BusinessInterface
    {
        public:
            BusinessService(){};
            ~BusinessService(){};

            IBusinessEntity* loadBusinessEntity(){
                IGroundEntity *ground = GroundFactory::createEntity();
                ISkyEntity *sky = SkyFactory::createEntity();
                IPopulationEntity *population = PopulationFactory::createEntity();
                IPlayerEntity *player = PlayerFactory::createEntity();

                IBusinessEntity *entity = BusinessFactory::createEntity(
                    player,
                    ground,
                    sky,
                    population
                );
                return entity;
            }
            bool loadSceneScreen();
            bool loadObjectFromSceneScreen();
            bool loadTerrainFromSceneScreen();
    };
} // business

#endif
