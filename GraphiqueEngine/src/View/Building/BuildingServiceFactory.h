#ifndef VIEW_BUILDING_SERVICE_FACTORY_H
#define VIEW_BUILDING_SERVICE_FACTORY_H

#include "../SceneNode/ISceneNodeService.h"
#include "BuildingService.h"

namespace graphique
{
    class BuildingServiceFactory
    {
        public:
            static IBuildingService* createService(ISceneNodeService *sceneNodeService, business::IBuildingEntity *entity) {
                return new BuildingService(sceneNodeService, entity);
            }
    };
} // graphique

#endif




