#ifndef VIEW_POPULATION_FPS_SERVICE_FACTORY_H
#define VIEW_POPULATION_FPS_SERVICE_FACTORY_H

#include "PopulationFPSService.h"

namespace graphique
{
    class PopulationFPSServiceFactory
    {
        public:
            static IPopulationService* createService(
                irr::IrrlichtDevice *device,
                business::IPopulationEntity *populationEntity
            ) {
                return new PopulationFPSService(device, populationEntity);
            }
    };
} // graphique

#endif



