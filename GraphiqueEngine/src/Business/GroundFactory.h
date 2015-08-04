#ifndef GROUND_FACTORY_H
#define GROUND_FACTORY_H

#include "GroundEntity.h"

namespace graphique
{
    class GroundFactory
    {
    public:
        static IGroundEntity* createEntity() {
            return new GroundEntity();
        }
    };
} // graphique

#endif
