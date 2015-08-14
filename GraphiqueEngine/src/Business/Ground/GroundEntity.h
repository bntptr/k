#ifndef GROUNDENTITY_H
#define GROUNDENTITY_H

#include "IGroundEntity.h"

namespace business
{
    class GroundEntity : public IGroundEntity
    {
        public:
            GroundEntity(){};
            ~GroundEntity(){};
            char* getMeshName(){
                return NULL;
            }
            IGroundEntity* setMesh(char* meshName){
                return NULL;
            }
    };
} // business

#endif
