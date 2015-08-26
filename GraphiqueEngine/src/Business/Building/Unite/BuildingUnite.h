#ifndef BUILDING_UNITE_H
#define BUILDING_UNITE_H

#include "IBuildingUnite.h"
#include "Action/Build.h"

namespace business
{
    class BuildingUnite : public IBuildingUnite
    {
        protected:
            IBuildingUnite *thisInstance;
            Vector3d position;
            Vector3d rotation;
            Vector3d scale;
            ETEXTURE texture;
            EMESH mesh;

        public:
            BuildingUnite(){
                this->thisInstance = this;
            };
            ~BuildingUnite(){};

            EMESH getMesh(){
                return this->mesh;
            }

            IBuildingUnite* setMesh(EMESH mesh){
                this->mesh = mesh;
                return this->thisInstance;
            }

            ETEXTURE getTexture(){
                return this->texture;
            }

            IBuildingUnite* setTexture(ETEXTURE texture){
                this->texture = texture;
                return this->thisInstance;
            }

            Vector3d getPosition(){
                return this->position;
            }

            IBuildingUnite* setPosition(Vector3d position) {
                this->position = position;
                return this->thisInstance;
            }

            Vector3d getRotation(){
                return this->rotation;
            }

            IBuildingUnite* setRotation(Vector3d rotation){
                this->rotation = rotation;
                return this->thisInstance;
            }

            Vector3d getScale(){
                return this->scale;
            }

            IBuildingUnite* setScale(Vector3d scale){
                this->scale = scale;
                return this->thisInstance;
            }

             bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                building::IAction *action;
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
                }
                return true;
            }
    };
} // business

#endif


