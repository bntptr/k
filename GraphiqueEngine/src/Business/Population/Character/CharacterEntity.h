#ifndef CHARACTERENTITY_H
#define CHARACTERENTITY_H

#include "ICharacterEntity.h"

namespace graphique
{
    class CharacterEntity : public ICharacterEntity
    {
        protected:
            ICharacterEntity *thisInstance;
            Vector3d position;
            Vector3d rotation;
            Vector3d scale;
            ETEXTURE texture;
            EMESH mesh;
        public:
            CharacterEntity(){
                this->thisInstance = this;
            };
            ~CharacterEntity(){};

            EMESH getMesh(){
                return this->mesh;
            }

            ICharacterEntity* setMesh(EMESH mesh){
                this->mesh = mesh;
                return this->thisInstance;
            }

            ETEXTURE getTexture(){
                return this->texture;
            }

            ICharacterEntity* setTexture(ETEXTURE texture){
                this->texture = texture;
                return this->thisInstance;
            }

            Vector3d getPosition(){
                return this->position;
            }

            ICharacterEntity* setPosition(Vector3d position){
                this->position = position;
                return this->thisInstance;
            }

            Vector3d getRotation(){
                return this->rotation;
            }

            ICharacterEntity* setRotation(Vector3d rotation){
                this->rotation = rotation;
                return this->thisInstance;
            }

            Vector3d getScale(){
                return this->scale;
            }

            ICharacterEntity* setScale(Vector3d scale){
                this->scale = scale;
                return this->thisInstance;
            }

            // Actions Character
            void deplaceX() {
                float newPosition = this->position.getX() + 1;
                this->position.setX(newPosition);
            }
    };
} // business

#endif


