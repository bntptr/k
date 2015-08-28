#ifndef VIEW_IENVIRONNEMENT_SERVICE_H
#define VIEW_IENVIRONNEMENT_SERVICE_H

//#include "IItem.h"

namespace graphique
{
    class IEnvironnementService
    {
        public:
            IEnvironnementService(){};
            virtual ~IEnvironnementService(){};

            virtual bool build()=0;
            virtual bool onEvent(const irr::SEvent& event)=0;
    };
}

#endif




