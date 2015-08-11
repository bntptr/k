#ifndef IACCESSORYENTITY_H
#define IACCESSORYENTITY_H

namespace graphique
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

