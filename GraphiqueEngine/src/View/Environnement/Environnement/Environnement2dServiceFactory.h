#ifndef VIEW_ENVVIRONNEMENT_2D_SERVICE_FACTORY_H
#define VIEW_ENVVIRONNEMENT_2D_SERVICE_FACTORY_H

#include "Environnement2dService.h"

namespace graphique
{
    class Environnement2dServiceFactory
    {
        public:
            static IEnvironnementService* createService(irr::IrrlichtDevice *device) {
                return new Environnement2dService(device);
            }
    };
} // graphique

#endif



