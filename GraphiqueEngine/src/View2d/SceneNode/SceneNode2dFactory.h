#ifndef VIEW_SCENE_NODE_2D_FACTORY_H
#define VIEW_SCENE_NODE_2D_FACTORY_H

#include "SceneNode2d.h"

namespace graphique
{
    class SceneNode2dFactory
    {
        public:
            static ISceneNode* createEntity(irr::IrrlichtDevice *device) {
                return new SceneNode2d(device);
            }
    };
} // graphique

#endif

