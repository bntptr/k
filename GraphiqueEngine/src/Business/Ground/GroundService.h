#ifndef BUSINESS_GROUND_SERVICE_H
#define BUSINESS_GROUND_SERVICE_H

#include "GroundEntity.h"
#include "IGroundService.h"

namespace business
{
    class GroundService : public IGroundService
    {
        protected:
            IGroundService* thisInstance;

        public:
            GroundService(){
                this->thisInstance = this;
            };
            ~GroundService(){};
    };
} // business

#endif



