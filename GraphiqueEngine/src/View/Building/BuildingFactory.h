#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "BuildingEntity.h"

namespace graphique
{
    class BuildingFactory
    {
        public:
            static IBuildingEntity* createEntity(ISceneNodeService *service, business::IBuildingEntity *entity) {
                return new BuildingEntity(service, entity);
            }
    };
} // graphique

#endif


