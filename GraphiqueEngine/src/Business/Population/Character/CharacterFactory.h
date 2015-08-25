#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "CharacterEntity.h"

namespace business
{
    // Moche !! ouhh !!!
    int nbCharacter = 0;
    class CharacterFactory
    {
        private:
            static int nbId;
        public:
            static ICharacterEntity* createEntity(
                Vector3d position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                TMap<EACTIONEVENT, character::IAction>* keyMap = new TMap<EACTIONEVENT, character::IAction>();
                //keyMap->addElement(EACTIONEVENT_DEFAULT, new character::Default());
                keyMap->addElement(EACTIONEVENT_DEPLACE_X, new character::DeplaceX());
                //keyMap->addElement(EACTIONEVENT_DEPLACE_Y, new character::DeplaceY());
                //keyMap->addElement(EACTIONEVENT_DEPLACE_Z, new character::DeplaceZ());

                ICharacterEntity *entity = new CharacterEntity(CharacterFactory::nbId, keyMap);
                CharacterFactory::nbId = CharacterFactory::nbId + 1;

                entity->setPosition(position);
                entity->setRotation(rotation);
                entity->setScale(scale);
                entity->setTexture(texture);
                entity->setMesh(mesh);
                return entity;
            }
    };
    int CharacterFactory::nbId = 1;
} // business

#endif
