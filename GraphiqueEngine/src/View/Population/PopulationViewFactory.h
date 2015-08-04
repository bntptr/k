#ifndef POPULATIONVIEW_FACTORY_H
#define POPULATIONVIEW_FACTORY_H

#include "PopulationView.h"

namespace graphique
{
    class PopulationViewFactory
    {
    public:
        static IPopulationView* createEntity() {
            return new PopulationView();
        }
    };
} // graphique

#endif

