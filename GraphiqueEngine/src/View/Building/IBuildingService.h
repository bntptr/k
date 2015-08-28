#ifndef IBUILDING_SERVICE_H
#define IBUILDING_SERVICE_H

#include "IBuildingEntity.h"

namespace graphique
{
    class IBuildingService
    {
        public:
            IBuildingService(){};
            virtual ~IBuildingService(){};

            virtual bool build()=0;

            virtual IBuildingEntity* getBuildingView()=0;
    };
}

#endif


