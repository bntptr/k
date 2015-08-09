#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "CharacterEntity.h"

namespace graphique
{
    class CharacterFactory
    {
    public:
        static ICharacterEntity* createEntity() {
            return new CharacterEntity();
        }
    };
} // graphique

#endif

