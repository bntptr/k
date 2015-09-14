#ifndef VIEW_SCENE_NODE_3D_SERVICE_FACTORY_H
#define VIEW_SCENE_NODE_3D_SERVICE_FACTORY_H

#include "SceneNode3dService.h"

namespace graphique
{
    class SceneNode3dServiceFactory
    {
        public:
            static ISceneNodeService* createService(irr::IrrlichtDevice *device) {
                return new SceneNode3dService(device);
            }
    };
} // graphique

#endif



