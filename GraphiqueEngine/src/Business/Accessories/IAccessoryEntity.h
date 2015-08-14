#ifndef IACCESSORYENTITY_H
#define IACCESSORYENTITY_H

namespace business
{
    class IAccessoryEntity
    {
        public:
            IAccessoryEntity(){};
            virtual ~IAccessoryEntity(){};
            virtual char* getMeshName()=0;
            virtual IAccessoryEntity* setMesh(char* meshName)=0;
    };
} // business

#endif

