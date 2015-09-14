#ifndef VIEW_SKY_SERVICE_FACTORY_H
#define VIEW_SKY_SERVICE_FACTORY_H

#include "SkyService.h"

namespace graphique
{
    class SkyServiceFactory
    {
        public:
            static ISkyService* createService(
                ISceneNodeService *service,
                business::ISkyEntity *skyEntity
            ) {
                return new SkyService(service, skyEntity);
            }
    };
} // graphique

#endif



