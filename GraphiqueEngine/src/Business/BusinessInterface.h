#ifndef BUSINESSINTERFACE_H
#define BUSINESSINTERFACE_H

#include "BusinessEntity.h"
#include "Ground/IGroundEntity.h"

namespace business
{
    class BusinessInterface
    {
        public:
            BusinessInterface(){};
            virtual ~BusinessInterface(){};

            virtual IBusinessEntity* loadBusinessEntity()=0;
    };
}

#endif
