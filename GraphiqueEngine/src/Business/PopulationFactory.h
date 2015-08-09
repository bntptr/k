#ifndef POPULATION_FACTORY_H
#define POPULATION_FACTORY_H

#include "PopulationEntity.h"

namespace graphique
{
    class PopulationFactory
    {
    public:
        static IPopulationEntity* createEntity() {
            IPopulationEntity* entity = new PopulationEntity();
            entity->addCharacter(
                Vector3d(0, 0, 0),
                Vector3d(0, 0, 0),
                Vector3d(2, 2, 2),
                ETEXTURE_NINJA,
                EMESH_NINJA
            );
            entity->addCharacter(
                Vector3d(10, 0, 0),
                Vector3d(0, 0, 0),
                Vector3d(2, 2, 2),
                ETEXTURE_NINJA_GREEN,
                EMESH_NINJA
            );
            return entity;
        }
    };
} // graphique

#endif
