#ifndef BUSINESS_POPULATION_SERVICE_H
#define BUSINESS_POPULATION_SERVICE_H

#include "PopulationEntity.h"
#include "IPopulationService.h"

namespace business
{
    class PopulationService : public IPopulationService
    {
        protected:
            IPopulationService* thisInstance;

        public:
            PopulationService(){
                this->thisInstance = this;
            };
            ~PopulationService(){};
    };
} // business

#endif



