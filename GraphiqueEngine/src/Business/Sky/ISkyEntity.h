#ifndef ISKYENTITY_H
#define ISKYENTITY_H

namespace business
{
    class ISkyEntity
    {
        public:
            ISkyEntity(){};
            virtual ~ISkyEntity(){};
            virtual char* getMeshName()=0;
            virtual ISkyEntity* setMesh(char* meshName)=0;
    };
} // business

#endif
