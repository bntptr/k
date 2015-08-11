#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "PlayerEntity.h"

namespace graphique
{
    class PlayerFactory
    {
    public:
        static IPlayerEntity* createEntity() {
            return new PlayerEntity();
        }
    };
} // graphique

#endif
