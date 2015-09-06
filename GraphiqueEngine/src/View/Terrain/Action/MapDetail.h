#ifndef VIEW_TERRAIN_MAPDETAIL_H
#define VIEW_TERRAIN_MAPDETAIL_H

#include "IAction.h"

namespace graphique
{
    namespace terrain
    {
        class MapDetail : public IAction
        {
            public:
                MapDetail(){};
                virtual ~MapDetail(){};

                int execute(ITerrainView *terrain) {
                    irr::scene::ISceneNode* Terrain = terrain
                        ->getSceneNode()
                        ->getIrrlichtSceneNode();
                    // toggle detail map
                    Terrain->setMaterialType(
                        Terrain->getMaterial(0).MaterialType == irr::video::EMT_SOLID ?
                        irr::video::EMT_DETAIL_MAP : irr::video::EMT_SOLID);
                }
        };
    }
} // graphique

#endif


