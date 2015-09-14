#ifndef POPULATIONVIEW_FACTORY_H
#define POPULATIONVIEW_FACTORY_H

#include "PopulationView.h"

namespace graphique
{
    class PopulationViewFactory
    {
        public:
            static IPopulationView* createEntity(
                ISceneNodeService *service,
                business::IPopulationEntity *populationEntity
            ) {
                return new PopulationView(service, populationEntity);
            }
    };
} // graphique

#endif

