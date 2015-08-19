#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "BuildingEntity.h"

namespace business
{
    class BuildingFactory
    {
        public:
            static IBuildingEntity* createEntity() {
                IBuildingEntity* entity = new BuildingEntity();
                entity->addBuildingUnite(
                    Vector3d(0, 0, 0),
                    Vector3d(0, 90, 0),
                    Vector3d(2, 2, 2),
                    ETEXTURE_NONE,
                    EMESH_CASTEL_IRR
                );
                mockEntity(entity);
                return entity;
            }

            /**
             * Personnages de tests
             */
            static IBuildingEntity* mockEntity(IBuildingEntity* entity) {
                return entity;
            }
    };
} // business

#endif
