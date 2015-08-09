#ifndef CHARACTERSERVICE_H
#define CHARACTERSERVICE_H

#include "CharacterFactory.h"

namespace graphique
{
    class CharacterService
    {
        public:
            CharacterService(){};
            ~CharacterService(){};

            ICharacter* loadBusinessEntity(){
                return NULL;
            }
    };
} // business

#endif

