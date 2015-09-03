#ifndef VIEW_SCENE_NODE_H
#define VIEW_SCENE_NODE_H

#include "ISceneNode.h"

namespace graphique
{
    class SceneNode : public ISceneNode
    {
        protected:
            ISceneNode* thisInstance;
            irr::IrrlichtDevice *device;

            int id;
            business::Vector3d position;
            business::Vector3d rotation;
            business::Vector3d scale;
            ETEXTURE texture;
            EMESH mesh;

        public:
            SceneNode(irr::IrrlichtDevice *device, int id=-1){
                this->thisInstance = this;
                this->device = device;
                this->id = id;
                this->build();
                this->setPosition(business::Vector3d(0,0,0));
                this->setRotation(business::Vector3d(0,0,0));
                this->setScale(business::Vector3d(1,1,1));
                this->texture = ETEXTURE_FAERIE;
                this->mesh = EMESH_FAERIE;
            };
            ~SceneNode(){};

            bool build() {

                return true;
            }

            bool draw() {

                return true;
            }

            bool onEvent(const irr::SEvent& event) {

                return true;
            }

            int getId() {
                return this->id;
            }

            EMESH getMesh(){
                return this->mesh;
            }

            ISceneNode* setMesh(EMESH mesh){
                this->mesh = mesh;
                return this->thisInstance;
            }

            ETEXTURE getTexture(){
                return this->texture;
            }

            ISceneNode* setTexture(ETEXTURE texture){
                this->texture = texture;
                return this->thisInstance;
            }

            business::Vector3d getPosition(){
                return this->position;
            }

            ISceneNode* setPosition(business::Vector3d position) {
                this->position = position;
                return this->thisInstance;
            }

            business::Vector3d getRotation(){
                return this->rotation;
            }

            ISceneNode* setRotation(business::Vector3d rotation){
                this->rotation = rotation;
                return this->thisInstance;
            }

            business::Vector3d getScale(){
                return this->scale;
            }

            ISceneNode* setScale(business::Vector3d scale){
                this->scale = scale;
                return this->thisInstance;
            }
    };
} // graphique

#endif
