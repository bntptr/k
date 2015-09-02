#ifndef VIEW_SCENE_NODE_SERVICE_H
#define VIEW_SCENE_NODE_SERVICE_H

#include "ISceneNodeService.h"
#include "SceneNodeFactory.h"

namespace graphique
{
    class SceneNodeService : public ISceneNodeService
    {
        protected:
            ISceneNodeService* thisInstance;
            ISceneNode *sceneNode;

        public:
            SceneNodeService(){
                this->thisInstance = this;
            };
            SceneNodeService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->sceneNode = SceneNodeFactory::createEntity(device);
            };
            ~SceneNodeService(){};

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



