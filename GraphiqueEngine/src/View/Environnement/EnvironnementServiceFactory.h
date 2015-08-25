#ifndef VIEW_ENVVIRONNEMENT_SERVICE_FACTORY_H
#define VIEW_ENVVIRONNEMENT_SERVICE_FACTORY_H

#include "EnvironnementService.h"

namespace graphique
{
    class EnvironnementServiceFactory
    {
        public:
            static IEnvironnementService* createService(irr::IrrlichtDevice *device) {
                return new EnvironnementService(device);
            }
    };
} // graphique

#endif



