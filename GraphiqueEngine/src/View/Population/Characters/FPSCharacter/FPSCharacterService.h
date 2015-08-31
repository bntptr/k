#ifndef FPSCHARACTER_SERVICE_H
#define FPSCHARACTER_SERVICE_H

#include "FPSCharacterFactory.h"
#include "../CharacterService.h"

namespace graphique
{
    class FPSCharacterService : public CharacterService
    {
        public:
            FPSCharacterService(){};
            ~FPSCharacterService(){};
    };
} // business

#endif

