#ifndef IPOPULATIONENTITY_H
#define IPOPULATIONENTITY_H

//#include <list>
#include "../Kutility/kutility.h"

#include "Character/Vector3d/Vector3d.h"
#include "Character/ICharacterEntity.h"

namespace graphique
{
    class IPopulationEntity
    {
        public:
            IPopulationEntity(){};
            virtual ~IPopulationEntity(){};
            //virtual std::list<ICharacterEntity*>* getCharacterList()=0;

            virtual TList<ICharacterEntity>* getCharacterList()=0;
            virtual IPopulationEntity* addCharacter(
                const Vector3d & position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            )=0;
    };
} // business

#endif
