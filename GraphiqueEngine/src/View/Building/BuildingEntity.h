#ifndef VIEW_BUILDING_ENTITY_H
#define VIEW_BUILDING_ENTITY_H

#include "IBuildingEntity.h"

namespace graphique
{
    class BuildingEntity : public IBuildingEntity
    {
        protected:
            ISceneNodeService *sceneNodeService;
            ISceneNode *node;
            irr::IrrlichtDevice *device;
            //scene::IMeshSceneNode* node;
            business::IBuildingEntity *buildingEntity;

        public:
            BuildingEntity(ISceneNodeService *service, business::IBuildingEntity *entity){
                this->sceneNodeService = service;
                this->buildingEntity = entity;
            };
            ~BuildingEntity(){};

            bool build() {
                this->node = this->sceneNodeService->addOctTreeSceneNode(
                    business::Vector3d(1350,-130,1400),
                    business::Vector3d(0,0,0),
                    business::Vector3d(1,1,1)
                );
                return true;
            }

            bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                //sky::IAction *action;
                switch(event)
                {
                    case EACTIONEVENT_CHANGE_SKY:
                        //action = new building::Build();
                        //action->execute(this);
                        break;
                    default:
                    break;
                }
                return true;
            }

            business::IBuildingEntity* getBuildingEntity() {
                return this->buildingEntity;
            }
    };
} // graphique

#endif

