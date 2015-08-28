#ifndef VIEW_VEGETAL_SERVICE_FACTORY_H
#define VIEW_VEGETAL_SERVICE_FACTORY_H

#include "VegetalService.h"

namespace graphique
{
    class VegetalServiceFactory
    {
        public:
            static IVegetalService* createService(irr::IrrlichtDevice *device, business::IVegetalEntity *entity) {
                return new VegetalService(device, entity);
            }
    };
} // graphique

#endif



