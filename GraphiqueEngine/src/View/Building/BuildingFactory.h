#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "BuildingEntity.h"

namespace graphique
{
    class BuildingFactory
    {
    public:
        static IBuildingEntity* createEntity(irr::IrrlichtDevice *device, business::IBuildingEntity *entity) {
            return new BuildingEntity(device, entity);
        }
    };
} // graphique

#endif


