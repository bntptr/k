#ifndef VIEW_POPULATION_FPS_VIEW_FACTORY_H
#define VIEW_POPULATION_FPS_VIEW_FACTORY_H

#include "PopulationFPSView.h"

namespace graphique
{
    class PopulationFPSViewFactory
    {
        public:
            static IPopulationView* createEntity(
                irr::IrrlichtDevice *device,
                business::IPopulationEntity *populationEntity
            ) {
                return new PopulationFPSView(device, populationEntity);
            }
    };
} // graphique

#endif

