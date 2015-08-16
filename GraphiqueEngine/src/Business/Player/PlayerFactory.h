#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "PlayerEntity.h"

namespace business
{
    class PlayerFactory
    {
        public:
            static IPlayerEntity* createEntity() {
                return new PlayerEntity();
            }
    };
} // business

#endif
