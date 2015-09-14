#ifndef VIEW_SCENE_NODE_2D_SERVICE_FACTORY_H
#define VIEW_SCENE_NODE_2D_SERVICE_FACTORY_H

#include "SceneNodeService.h"

namespace graphique
{
    class SceneNode2dServiceFactory
    {
        public:
            static ISceneNodeService* createService(irr::IrrlichtDevice *device) {
                return new SceneNode2dService(device);
            }
    };
} // graphique

#endif



