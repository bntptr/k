#ifndef BUSINESS_POPULATION_SERVICE_FACTORY_H
#define BUSINESS_POPULATION_SERVICE_FACTORY_H

#include "PopulationService.h"

namespace business
{
    class PopulationServiceFactory
    {
        public:
            static IPopulationService* createService() {
                return new PopulationService();
            }
    };
} // business

#endif





