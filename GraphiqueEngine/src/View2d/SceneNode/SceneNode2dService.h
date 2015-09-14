#ifndef VIEW_SCENE_NODE_2D_SERVICE_H
#define VIEW_SCENE_NODE_2D_SERVICE_H

#include "SceneNodeService.h"
#include "SceneNode2dFactory.h"

namespace graphique
{
    class SceneNode2dService : public SceneNodeService
    {
        public:
            SceneNode2dService(){
                this->thisInstance = this;
            };
            SceneNode2dService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->sceneNode = SceneNode2dFactory::createEntity(device);
            };
            ~SceneNode2dService(){};

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



