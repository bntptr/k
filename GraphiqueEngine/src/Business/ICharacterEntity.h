#ifndef ICHARACTERENTITY_H
#define ICHARACTERENTITY_H

namespace graphique
{
    class ICharacterEntity
    {
        public:
            ICharacterEntity(){};
            virtual ~ICharacterEntity(){};
            virtual char* getMeshName()=0;
            virtual ICharacterEntity* setMesh(char* meshName)=0;
    };
} // business

#endif
