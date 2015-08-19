#ifndef BUSINESS_BUILDING_UNITE_IACTION_H
#define BUSINESS_BUILDING_UNITE_IACTION_H

#include "../IBuildingUnite.h"

namespace business
{
    namespace building
    {
        class IAction
        {
            public:
                IAction(){};
                virtual ~IAction(){};

                virtual int execute(IBuildingUnite *character)=0;
        };
    }
} // business

#endif



