#ifndef BUSINESS_GROUND_SERVICE_FACTORY_H
#define BUSINESS_GROUND_SERVICE_FACTORY_H

#include "GroundService.h"

namespace business
{
    class GroundServiceFactory
    {
        public:
            static IGroundService* createService() {
                return new GroundService();
            }
    };
} // business

#endif





