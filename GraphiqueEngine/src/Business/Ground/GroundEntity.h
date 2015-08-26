#ifndef GROUNDENTITY_H
#define GROUNDENTITY_H

#include "IGroundEntity.h"

namespace business
{
    class GroundEntity : public IGroundEntity
    {
        protected:
            IGroundEntity *thisInstance;
            Vector3d position;
            Vector3d rotation;
            Vector3d scale;
            ETEXTURE texture;
            EMESH mesh;

        public:
            GroundEntity(){
                this->thisInstance = this;
            };
            ~GroundEntity(){};

            EMESH getMesh(){
                return this->mesh;
            }

            IGroundEntity* setMesh(EMESH mesh){
                this->mesh = mesh;
                return this->thisInstance;
            }

            ETEXTURE getTexture(){
                return this->texture;
            }

            IGroundEntity* setTexture(ETEXTURE texture){
                this->texture = texture;
                return this->thisInstance;
            }

            Vector3d getPosition(){
                return this->position;
            }

            IGroundEntity* setPosition(Vector3d position) {
                this->position = position;
                return this->thisInstance;
            }

            Vector3d getRotation(){
                return this->rotation;
            }

            IGroundEntity* setRotation(Vector3d rotation){
                this->rotation = rotation;
                return this->thisInstance;
            }

            Vector3d getScale(){
                return this->scale;
            }

            IGroundEntity* setScale(Vector3d scale){
                this->scale = scale;
                return this->thisInstance;
            }

            bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                /*ground::IAction *action;
                switch(event)
                {
                    case EACTIONEVENT_DEFAULT:
                        break;
                    case EACTIONEVENT_DEPLACE_X:
                        action = new character::DeplaceX();
                        action->execute(this);
                        break;
                    case EACTIONEVENT_DEPLACE_Y:
                        break;
                    case EACTIONEVENT_DEPLACE_Z:
                        break;
                    default:
                    break;
                }*/
                return true;
            }
    };
} // business

#endif
