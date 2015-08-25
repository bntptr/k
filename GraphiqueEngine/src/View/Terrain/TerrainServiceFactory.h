#ifndef VIEW_TERRAIN_SERVICE_FACTORY_H
#define VIEW_TERRAIN_SERVICE_FACTORY_H

#include "TerrainService.h"

namespace graphique
{
    class TerrainServiceFactory
    {
        public:
            static ITerrainService* createService(irr::IrrlichtDevice *device, business::IGroundEntity *ground) {
                return new TerrainService(device, ground);
            }
    };
} // graphique

#endif



