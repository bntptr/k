#ifndef BUSINESS_SKY_SERVICE_FACTORY_H
#define BUSINESS_SKY_SERVICE_FACTORY_H

#include "SkyService.h"

namespace business
{
    class SkyServiceFactory
    {
        public:
            static ISkyService* createService() {
                return new SkyService();
            }
    };
} // business

#endif




