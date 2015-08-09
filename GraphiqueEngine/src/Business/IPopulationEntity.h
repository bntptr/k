#ifndef IPOPULATIONENTITY_H
#define IPOPULATIONENTITY_H

#include <list>

#include "ICharacterEntity.h"

namespace graphique
{
    class IPopulationEntity
    {
        public:
            virtual std::list<ICharacterEntity*>* getCharacterList()=0;
            //virtual IPopulationEntity* addCharacter()=0;
    };
} // business

#endif
