#ifndef BUILDING_SERVICE_H
#define BUILDING_SERVICE_H

#include "BuildingEntity.h"
#include "IBuildingService.h"

namespace graphique
{
    class BuildingService : public IBuildingService
    {
        protected:
            IBuildingService* thisInstance;

        public:
            BuildingService(){
                this->thisInstance = this;
            };
            ~BuildingService(){};
    };
} // business

#endif

