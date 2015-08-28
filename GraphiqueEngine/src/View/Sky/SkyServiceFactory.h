#ifndef VIEW_SKY_SERVICE_FACTORY_H
#define VIEW_SKY_SERVICE_FACTORY_H

#include "SkyService.h"

namespace graphique
{
    class SkyServiceFactory
    {
        public:
            static ISkyService* createService(irr::IrrlichtDevice *device, business::ISkyEntity *skyEntity) {
                return new SkyService(device, skyEntity);
            }
    };
} // graphique

#endif



