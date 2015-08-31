#ifndef FPSCHARACTER_VIEW_FACTORY_H
#define FPSCHARACTER_VIEW_FACTORY_H

#include "FPSCharacter.h"

namespace graphique
{
    class FPSCharacterFactory
    {
        public:
            static IFPSCharacter* createEntity(irr::IrrlichtDevice *device, business::ICharacterEntity *entity) {
                return new FPSCharacter(device, entity);
            }
    };
} // graphique

#endif



