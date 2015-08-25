#ifndef BUSINESS_ACCESSORY_SERVICE_H
#define BUSINESS_ACCESSORY_SERVICE_H

#include "AccessoryEntity.h"
#include "IAccessoryService.h"

namespace business
{
    class AccessoryService : public IAccessoryService
    {
        protected:
            IAccessoryService* thisInstance;

        public:
            AccessoryService(){
                this->thisInstance = this;
            };
            ~AccessoryService(){};
    };
} // business

#endif



