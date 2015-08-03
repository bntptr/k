#ifndef SKYENTITY_H
#define SKYENTITY_H

namespace graphique
{
    class ISkyEntity
    {
    public:
        virtual char* getMeshName();
        virtual ISkyEntity* setMesh(char* meshName);
    };
} // business

#endif
