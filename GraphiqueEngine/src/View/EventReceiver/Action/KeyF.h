#ifndef IACTIONKEY_F_H
#define IACTIONKEY_F_H

#include "IKey.h"

namespace graphique
{
    class KeyF : public IKey
    {
        public:
            KeyF(){};
            virtual ~KeyF(){};

            int execute(IView *view) {
                irr::scene::ISceneNode* Terrain = view->getTerrain()->getTerrain();
                 // switch wire frame mode
                Terrain->setMaterialFlag(irr::video::EMF_POINTCLOUD,
                        !Terrain->getMaterial(0).PointCloud);
                Terrain->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
            }
    };
} // graphique

#endif


