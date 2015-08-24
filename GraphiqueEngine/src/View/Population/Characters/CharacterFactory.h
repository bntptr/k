#ifndef CHARACTERVIEW_FACTORY_H
#define CHARACTERVIEW_FACTORY_H

#include "Character.h"

namespace graphique
{
    class CharacterFactory
    {
        public:
            static ICharacter* createEntity(irr::IrrlichtDevice *device, business::ICharacterEntity *entity) {
                TMap<EACTIONEVENT, character::IAction>* keyMap = new TMap<EACTIONEVENT, character::IAction>();
                //keyMap->addElement(EACTIONEVENT_DEFAULT, new character::Default());
                keyMap->addElement(EACTIONEVENT_DEPLACE_X, new character::DeplaceX());
                //keyMap->addElement(EACTIONEVENT_DEPLACE_Y, new character::DeplaceY());
                //keyMap->addElement(EACTIONEVENT_DEPLACE_Z, new character::DeplaceZ());

                return new Character(device, entity, keyMap);
            }
    };
} // graphique

#endif



