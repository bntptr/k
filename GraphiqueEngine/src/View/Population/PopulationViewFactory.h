#ifndef POPULATIONVIEW_FACTORY_H
#define POPULATIONVIEW_FACTORY_H

#include "PopulationView.h"

namespace graphique
{
    class PopulationViewFactory
    {
    public:
        static IPopulationView* createEntity(irr::IrrlichtDevice *device, IPopulationEntity *populationEntity) {
            return new PopulationView(device, populationEntity);
        }
    };
} // graphique

#endif

