#ifndef IGROUNDENTITY_H
#define IGROUNDENTITY_H

namespace graphique
{
    class IGroundEntity
    {
    public:
        virtual char* getMeshName();
        virtual IGroundEntity* setMesh(char* meshName);
    };
} // business

#endif
