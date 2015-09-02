#ifndef VIEW_SCENE_NODE_SERVICE_FACTORY_H
#define VIEW_SCENE_NODE_SERVICE_FACTORY_H

#include "SceneNodeService.h"

namespace graphique
{
    class SceneNodeServiceFactory
    {
        public:
            static ISceneNodeService* createService(irr::IrrlichtDevice *device) {
                return new SceneNodeService(device);
            }
    };
} // graphique

#endif



