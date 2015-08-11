#ifndef IGROUNDENTITY_H
#define IGROUNDENTITY_H

namespace graphique
{
    class IGroundEntity
    {
        public:
            IGroundEntity(){};
            virtual ~IGroundEntity(){};
            virtual char* getMeshName()=0;
            virtual IGroundEntity* setMesh(char* meshName)=0;
    };
} // business

#endif
