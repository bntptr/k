#ifndef VIEW_TERRAIN_MAPTRIANGLE_H
#define VIEW_TERRAIN_MAPTRIANGLE_H

#include "IAction.h"

namespace graphique
{
    namespace terrain
    {
        class MapTriangle : public IAction
        {
            public:
                MapTriangle(){};
                virtual ~MapTriangle(){};

                int execute(ITerrainView *terrain) {
                    irr::scene::ISceneNode* Terrain = terrain->getTerrain();
                    // switch wire frame mode
                    Terrain->setMaterialFlag(irr::video::EMF_WIREFRAME,
                            !Terrain->getMaterial(0).Wireframe);
                    Terrain->setMaterialFlag(irr::video::EMF_POINTCLOUD, false);
                }
        };
    }
} // graphique

#endif


