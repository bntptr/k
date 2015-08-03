#ifndef BUSINESSINTERFACE_H
#define BUSINESSINTERFACE_H

#include "BusinessEntity.h"
#include "IGroundEntity.h"

namespace graphique
{
    class BusinessInterface
    {
        public:
            BusinessInterface(){};
            virtual ~BusinessInterface(){};

            virtual BusinessEntity* loadBusinessEntity()=0;
    };
}

#endif
