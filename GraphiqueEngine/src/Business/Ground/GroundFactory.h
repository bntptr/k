#ifndef GROUND_FACTORY_H
#define GROUND_FACTORY_H

#include "GroundEntity.h"

namespace business
{
    class GroundFactory
    {
        public:
            static IGroundEntity* createEntity(
                Vector3d position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh) {
                IGroundEntity *entity = new GroundEntity();
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
