#ifndef TERRAINVIEW_FACTORY_H
#define TERRAINVIEW_FACTORY_H

#include "TerrainView.h"

namespace graphique
{
    class TerrainViewFactory
    {
        public:
            static ITerrainView* createEntity(
                ISceneNodeService *service,
                business::IGroundEntity *ground
            ) {
                TMap<EACTIONEVENT, terrain::IAction>* keyMap = new TMap<EACTIONEVENT, terrain::IAction>();
                keyMap->addElement(EACTIONEVENT_TERRAIN_MAP_DETAIL, new terrain::MapDetail());
                keyMap->addElement(EACTIONEVENT_TERRAIN_MAP_TRIANGLE, new terrain::MapTriangle());
                keyMap->addElement(EACTIONEVENT_TERRAIN_MAP_POINT, new terrain::MapPoint());
                return new TerrainView(service, ground, keyMap);
            }
    };
} // graphique

#endif



