#ifndef VIEW_POPULATION_SERVICE_FACTORY_H
#define VIEW_POPULATION_SERVICE_FACTORY_H

#include "PopulationService.h"

namespace graphique
{
    class PopulationServiceFactory
    {
        public:
            static IPopulationService* createService(
                ISceneNodeService *service,
                business::IPopulationEntity *populationEntity
            ) {
                return new PopulationService(service, populationEntity);
            }
    };
} // graphique

#endif



