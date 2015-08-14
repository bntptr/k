#ifndef TERRAINVIEW_FACTORY_H
#define TERRAINVIEW_FACTORY_H

#include "TerrainView.h"

namespace graphique
{
    class TerrainViewFactory
    {
    public:
        static ITerrainView* createEntity(irr::IrrlichtDevice *device, business::IGroundEntity *ground) {
            return new TerrainView(device, ground);
        }
    };
} // graphique

#endif


