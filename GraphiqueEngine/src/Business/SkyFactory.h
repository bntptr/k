#ifndef SKY_FACTORY_H
#define SKY_FACTORY_H

#include "SkyEntity.h"

namespace graphique
{
    class SkyFactory
    {
    public:
        static ISkyEntity* createEntity() {
            return new SkyEntity();
        }
    };
} // graphique

#endif
