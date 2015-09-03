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
            TList<ISceneNode>* sceneNodeList;

            irr::IrrlichtDevice *device;

        public:
            SceneNodeService(){
                this->thisInstance = this;
            };
            SceneNodeService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->sceneNodeList = new TList<ISceneNode>();
                this->device = device;
            };
            ~SceneNodeService(){};

            bool build() {
                TList<ISceneNode>* L = this->sceneNodeList;
                for(int i = 0; i < L->size(); i++) {
                    L->getElement(i)->build();
                }
                return true;
            }

            bool draw() {
                TList<ISceneNode>* L = this->sceneNodeList;
                for(int i = 0; i < L->size(); i++) {
                    L->getElement(i)->draw();
                }
                return true;
            }

            bool onEvent(const irr::SEvent& event) {
                TList<ISceneNode>* L = this->sceneNodeList;
                for(int i = 0; i < L->size(); i++) {
                    L->getElement(i)->onEvent(event);
                }
                return true;
            }

            ISceneNodeService* addCubeSceneNode() {
                return this->thisInstance;
            }

            ISceneNodeService* addSphereSceneNode() {
                return this->thisInstance;
            }

            ISceneNodeService* addOctTreeSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale
            ) {
                ISceneNode *node = SceneNodeFactory::createOctTreeSceneNode(
                    this->device,
                    position,
                    rotation,
                    scale
                );
                this->sceneNodeList->addElement(node);
                return this->thisInstance;
            }

            ISceneNodeService* addCharacterSceneNode() {
                return this->thisInstance;
            }

            ISceneNodeService* addTerrainSceneNode() {
                return this->thisInstance;
            }

            ISceneNodeService* addSkySceneNode() {
                return this->thisInstance;
            }
    };
} // business

#endif



