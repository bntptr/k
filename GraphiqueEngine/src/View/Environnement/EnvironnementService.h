#ifndef VIEW_ENVIRONNEMENT_SERVICE_H
#define VIEW_ENVIRONNEMENT_SERVICE_H

#include "Item/Item.h"
#include "IEnvironnementService.h"

namespace graphique
{
    class EnvironnementService : public IEnvironnementService
    {
        protected:
            IEnvironnementService* thisInstance;

        public:
            EnvironnementService(){
                this->thisInstance = this;
            };
            ~EnvironnementService(){};
    };
} // business

#endif



