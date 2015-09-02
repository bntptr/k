#ifndef VIEW_SCENE_NODE_FACTORY_H
#define VIEW_SCENE_NODE_FACTORY_H

#include "SceneNode.h"

namespace graphique
{
    class SceneNodeFactory
    {
        public:
            static ISceneNode* createEntity(irr::IrrlichtDevice *device) {
                return new SceneNode(device);
            }
    };
} // graphique

#endif

