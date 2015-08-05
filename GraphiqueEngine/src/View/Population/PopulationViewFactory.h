#ifndef POPULATIONVIEW_FACTORY_H
#define POPULATIONVIEW_FACTORY_H

#include "PopulationView.h"

namespace graphique
{
    class PopulationViewFactory
    {
    public:
        static IPopulationView* createEntity(irr::IrrlichtDevice *device) {
            return new PopulationView(device);
        }
    };
} // graphique

#endif

