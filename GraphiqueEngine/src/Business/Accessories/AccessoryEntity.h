#ifndef ACCESSORYENTITY_H
#define ACCESSORYENTITY_H

#include "IAccessoryEntity.h"

namespace graphique
{
    class AccessoryEntity : public IAccessoryEntity
    {
        public:
            AccessoryEntity(){};
            ~AccessoryEntity(){};
            char* getMeshName(){
                return NULL;
            }
            IAccessoryEntity* setMesh(char* meshName){
                return NULL;
            }
    };
} // business

#endif

