#ifndef VIEW_TERRAIN_MAPPOINT_H
#define VIEW_TERRAIN_MAPPOINT_H

#include "IAction.h"

namespace graphique
{
    namespace terrain
    {
        class MapPoint : public IAction
        {
            public:
                MapPoint(){};
                virtual ~MapPoint(){};

                int execute(ITerrainView *terrain) {
                    irr::scene::ISceneNode* Terrain = terrain
                        ->getSceneNode()
                        ->getIrrlichtSceneNode();
                     // switch wire frame mode
                    Terrain->setMaterialFlag(irr::video::EMF_POINTCLOUD,
                            !Terrain->getMaterial(0).PointCloud);
                    Terrain->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
                }
        };
    }
} // graphique

#endif


