#ifndef BUILDING_UNITE_FACTORY_H
#define BUILDING_UNITE_FACTORY_H

#include "BuildingUnite.h"

namespace business
{
    class BuildingUniteFactory
    {
        public:
            static IBuildingUnite* createEntity(
                Vector3d position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh) {
                IBuildingUnite *entity = new BuildingUnite();
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

