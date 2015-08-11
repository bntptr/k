#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "IPlayerEntity.h"

namespace graphique
{
    class PlayerEntity : public IPlayerEntity
    {
        public:
            PlayerEntity(){};
            ~PlayerEntity(){};
    };
} // business

#endif
