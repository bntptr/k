#ifndef VIEW_BUILDING_SERVICE_FACTORY_H
#define VIEW_BUILDING_SERVICE_FACTORY_H

#include "BuildingService.h"

namespace graphique
{
    class BuildingServiceFactory
    {
        public:
            static IBuildingService* createService(irr::IrrlichtDevice *device, business::IBuildingEntity *entity) {
                return new BuildingService(device, entity);
            }
    };
} // graphique

#endif




