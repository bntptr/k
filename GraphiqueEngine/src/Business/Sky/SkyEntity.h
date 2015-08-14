#ifndef SKYENTITY_H
#define SKYENTITY_H

#include "ISkyEntity.h"

namespace business
{
    class SkyEntity : public ISkyEntity
    {
        public:
            SkyEntity(){};
            ~SkyEntity(){};
            char* getMeshName() {
                return NULL;
            }
            ISkyEntity* setMesh(char* meshName){
                return NULL;
            }
    };
} // business

#endif
