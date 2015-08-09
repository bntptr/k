#ifndef CHARACTERENTITY_H
#define CHARACTERENTITY_H

#include "ICharacterEntity.h"

namespace graphique
{
    class CharacterEntity : public ICharacterEntity
    {
        public:
            CharacterEntity(){};
            ~CharacterEntity(){};
            char* getMeshName(){
                return NULL;
            }
            ICharacterEntity* setMesh(char* meshName){
                return NULL;
            }
    };
} // business

#endif


