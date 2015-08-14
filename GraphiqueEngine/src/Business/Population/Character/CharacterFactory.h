#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "CharacterEntity.h"

//using namespace graphique;

namespace business
{
    class CharacterFactory
    {
    public:
        static ICharacterEntity* createEntity(
            Vector3d position,
            Vector3d rotation,
            Vector3d scale,
            ETEXTURE texture,
            EMESH mesh) {
            ICharacterEntity *entity = new CharacterEntity();
            entity->setPosition(position);
            entity->setRotation(rotation);
            entity->setScale(scale);
            entity->setTexture(texture);
            entity->setMesh(mesh);
            return entity;
        }
    };
} // business

#endif

