#ifndef VIEW_PLAYER_SERVICE_H
#define VIEW_PLAYER_SERVICE_H

#include "PlayerView.h"
#include "IPlayerService.h"

namespace graphique
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



