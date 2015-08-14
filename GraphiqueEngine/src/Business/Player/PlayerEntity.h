#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "IPlayerEntity.h"

namespace business
{
    class PlayerEntity : public IPlayerEntity
    {
        public:
            PlayerEntity(){};
            ~PlayerEntity(){};
    };
} // business

#endif
