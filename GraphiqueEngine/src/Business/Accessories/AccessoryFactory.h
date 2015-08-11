#ifndef ACCESSORY_FACTORY_H
#define ACCESSORY_FACTORY_H

#include "AccessoryEntity.h"

namespace graphique
{
    class AccessoryFactory
    {
    public:
        static IAccessoryEntity* createEntity() {
            return new AccessoryEntity();
        }
    };
} // graphique

#endif


