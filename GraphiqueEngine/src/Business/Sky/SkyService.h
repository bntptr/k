#ifndef BUSINESS_SKY_SERVICE_H
#define BUSINESS_SKY_SERVICE_H

#include "SkyEntity.h"
#include "ICursorService.h"

namespace business
{
    class SkyService : public ISkyService
    {
        protected:
            ISkyService* thisInstance;

        public:
            SkyService(){
                this->thisInstance = this;
            };
            ~SkyService(){};
    };
} // business

#endif



