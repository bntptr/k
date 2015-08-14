#ifndef CHARACTERVIEW_FACTORY_H
#define CHARACTERVIEW_FACTORY_H

#include "Character.h"

namespace graphique
{
    class CharacterFactory
    {
    public:
        static ICharacter* createEntity(irr::IrrlichtDevice *device, business::ICharacterEntity *entity) {
            return new Character(device, entity);
        }
    };
} // graphique

#endif



