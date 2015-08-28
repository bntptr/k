#ifndef BUSINESS_PLAYER_SERVICE_H
#define BUSINESS_PLAYER_SERVICE_H

#include "PlayerEntity.h"
#include "ICursorService.h"

namespace business
{
    class PlayerService : public IPlayerService
    {
        protected:
            IPlayerService* thisInstance;

        public:
            PlayerService(){
                this->thisInstance = this;
            };
            ~PlayerService(){};
    };
} // business

#endif



