#ifndef GROUND_FACTORY_H
#define GROUND_FACTORY_H

#include "GroundEntity.h"

namespace business
{
    class GroundFactory
    {
    public:
        static IGroundEntity* createEntity() {
            return new GroundEntity();
        }
    };
} // business

#endif
