#ifndef VIEW_SKY_SERVICE_H
#define VIEW_SKY_SERVICE_H

#include "SkyView.h"
#include "ISkyService.h"

namespace graphique
{
    class SkyService : public ISkyService
    {
        protected:
            ISkyService* thisInstance;

        public:
            SkyService(){
                this->thisInstance = this;
            };
            ~SkyService(){};
    };
} // business

#endif



