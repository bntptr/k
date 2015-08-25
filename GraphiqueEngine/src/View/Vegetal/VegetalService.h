#ifndef VIEW_VEGETAL_SERVICE_H
#define VIEW_VEGETAL_SERVICE_H

#include "IVegetalEntity.h"
#include "IVegetalService.h"

namespace graphique
{
    class VegetalService : public IVegetalService
    {
        protected:
            IVegetalService* thisInstance;

        public:
            VegetalService(){
                this->thisInstance = this;
            };
            ~VegetalService(){};
    };
} // business

#endif



