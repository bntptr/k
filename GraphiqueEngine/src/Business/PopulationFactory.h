#ifndef POPULATION_FACTORY_H
#define POPULATION_FACTORY_H

#include "PopulationEntity.h"

namespace graphique
{
    class PopulationFactory
    {
    public:
        static IPopulationEntity* createEntity() {
            return new PopulationEntity();
        }
    };
} // graphique

#endif
