#ifndef FPSCHARACTER_SERVICE_H
#define FPSCHARACTER_SERVICE_H

#include "FPSCharacterFactory.h"

namespace graphique
{
    class FPSCharacterService
    {
        public:
            FPSCharacterService(){};
            ~FPSCharacterService(){};

            IFPSCharacter* loadBusinessEntity(){
                return NULL;
            }
    };
} // business

#endif

