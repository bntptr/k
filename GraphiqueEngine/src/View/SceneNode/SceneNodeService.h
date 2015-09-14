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
            ICameraService* camera;

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
                    L->getElement(i)->build(this->camera);
                }
                return true;
            }

            bool draw() {
                TList<ISceneNode>* L = this->sceneNodeList;
                for(int i = 0; i < L->size(); i++) {
                    L->getElement(i)->draw(
                        this->camera->getCamera()->getPosition(),
                        this->camera->getCamera()->getScale()
                    );
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

            ISceneNodeService* setCameraService(ICameraService* camera) {
                this->camera = camera;
                return this->thisInstance;
            }

            ISceneNode* addCubeSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture
            ) {
                ISceneNode *node = SceneNodeFactory::createCubeSceneNode(
                    this->device,
                    position,
                    rotation,
                    scale,
                    texture
                );
                this->sceneNodeList->addElement(node);
                return node;
            }

            ISceneNode* addSphereSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture
            ) {
                ISceneNode *node = SceneNodeFactory::createSphereSceneNode(
                    this->device,
                    position,
                    rotation,
                    scale,
                    texture
                );
                this->sceneNodeList->addElement(node);
                return node;
            }

            ISceneNode* addOctTreeSceneNode(
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
                return node;
            }

            ISceneNode* addCharacterSceneNode(
                int id,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                ISceneNode *node = SceneNodeFactory::createCharacterSceneNode(
                    this->device,
                    id,
                    position,
                    rotation,
                    scale,
                    texture,
                    mesh
                );
                this->sceneNodeList->addElement(node);
                return node;
            }

            ISceneNode* addTerrainSceneNode(
                int id,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                ISceneNode *node = SceneNodeFactory::createTerrainSceneNode(
                    this->device,
                    position,
                    rotation,
                    scale,
                    texture,
                    mesh
                );
                this->sceneNodeList->addElement(node);
                return node;
            }

            ISceneNode* addSkyBoxSceneNode(
                ETEXTURE textureSkyBoxUp,
                ETEXTURE textureSkyBoxDn,
                ETEXTURE textureSkyBoxLf,
                ETEXTURE textureSkyBoxRt,
                ETEXTURE textureSkyBoxFt,
                ETEXTURE textureSkyBoxBk
            ) {
                ISceneNode *node = SceneNodeFactory::createSkyBoxSceneNode(
                    this->device,
                    textureSkyBoxUp,
                    textureSkyBoxDn,
                    textureSkyBoxLf,
                    textureSkyBoxRt,
                    textureSkyBoxFt,
                    textureSkyBoxBk
                );
                this->sceneNodeList->addElement(node);
                return node;
            }

            ISceneNode* addSkyDomeSceneNode(
                ETEXTURE textureSkyDome
            ) {
                ISceneNode *node = SceneNodeFactory::createSkyDomeSceneNode(
                    this->device,
                    textureSkyDome
                );
                this->sceneNodeList->addElement(node);
                return node;
            }
    };
} // business

#endif



