#ifndef VIEW_SCENE_NODE_3D_SERVICE_H
#define VIEW_SCENE_NODE_3D_SERVICE_H

#include "SceneNodeService.h"
#include "SceneNode3dFactory.h"

namespace graphique
{
    class SceneNode3dService : public SceneNode3dService
    {
        public:
            SceneNode3dService(){
                this->thisInstance = this;
            };
            SceneNode3dService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->sceneNode = SceneNode3dFactory::createEntity(device);
            };
            ~SceneNode3dService(){};

            bool build() {
                return this->sceneNode->build();
            }

            bool draw() {
                return this->sceneNode->draw();
            }

            bool onEvent(const irr::SEvent& event) {
                return this->environnement->onEvent(event);
            }
    };
} // business

#endif



