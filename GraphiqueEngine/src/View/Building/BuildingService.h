#ifndef BUILDING_SERVICE_H
#define BUILDING_SERVICE_H

#include "BuildingFactory.h"
#include "IBuildingService.h"

namespace graphique
{
    class BuildingService : public IBuildingService
    {
        protected:
            IBuildingService* thisInstance;
            IBuildingEntity *building;

        public:
            BuildingService(irr::IrrlichtDevice *device, business::IBuildingEntity *entity){
                this->thisInstance = this;
                this->building = BuildingFactory::createEntity(device, entity);
            };
            ~BuildingService(){};

            bool build() {
                this->building->build();
            }

            bool onEvent(EACTIONEVENT event) {
                return this->building->onEvent(event);
            }
    };
} // business

#endif

