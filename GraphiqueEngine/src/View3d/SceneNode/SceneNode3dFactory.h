#ifndef VIEW_SCENE_NODE_3D_FACTORY_H
#define VIEW_SCENE_NODE_3D_FACTORY_H

#include "SceneNode3d.h"

namespace graphique
{
    class SceneNode3dFactory
    {
        public:
            static ISceneNode* createEntity(irr::IrrlichtDevice *device) {
                return new SceneNode3d(device);
            }
    };
} // graphique

#endif

