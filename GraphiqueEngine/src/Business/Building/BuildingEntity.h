#ifndef BUILDING_ENTITY_H
#define BUILDING_ENTITY_H

#include "IBuildingEntity.h"
#include "Unite/BuildingUniteFactory.h"

namespace business
{
    class BuildingEntity : public IBuildingEntity
    {
        protected:
            IBuildingEntity *thisInstance;
            TList<IBuildingUnite>* buildingList;
        public:
            BuildingEntity(){
                this->thisInstance = this;
                this->buildingList = new TList<IBuildingUnite>();
            };
            ~BuildingEntity(){};

            TList<IBuildingUnite>* getBuildingList() {
                return this->buildingList;
            }

            IBuildingEntity* addBuildingUnite(
                const Vector3d & position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                IBuildingUnite *entity = business::BuildingUniteFactory::createEntity(
                    position,
                    rotation,
                    scale,
                    texture,
                    mesh
                );
                this->buildingList->addElement(entity);
                return this->thisInstance;
            }
    };
} // business

#endif
