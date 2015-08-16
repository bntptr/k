#ifndef BUILDING_ENTITY_H
#define BUILDING_ENTITY_H

#include "IBuildingEntity.h"

namespace business
{
    class BuildingEntity : public IBuildingEntity
    {
        public:
            BuildingEntity(){};
            ~BuildingEntity(){};

            char* getMeshName(){
                return NULL;
            }

            IBuildingEntity* setMesh(char* meshName){
                return NULL;
            }
    };
} // business

#endif
