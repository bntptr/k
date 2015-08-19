#ifndef IBUILDING_ENTITY_H
#define IBUILDING_ENTITY_H

#include "../../Kutility/kutility.h"

#include "Unite/IBuildingUnite.h"

namespace business
{
    class IBuildingEntity
    {
        public:
            IBuildingEntity(){};
            virtual ~IBuildingEntity(){};

            virtual TList<IBuildingUnite>* getBuildingList()=0;
            virtual IBuildingEntity* addCharacter(
                const Vector3d & position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            )=0;
    };
} // business

#endif
