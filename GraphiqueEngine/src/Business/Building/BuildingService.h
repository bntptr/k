#ifndef BUSINESS_BUILDING_SERVICE_H
#define BUSINESS_BUILDING_SERVICE_H

#include "BuildingEntity.h"
#include "IBuildingService.h"

namespace business
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



