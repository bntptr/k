#ifndef VIEW_POPULATION_SERVICE_H
#define VIEW_POPULATION_SERVICE_H

#include "PopulationView.h"
#include "IPopulationService.h"

namespace graphique
{
    class PopulationService : public IPopulationService
    {
        protected:
            IPopulationService* thisInstance;

        public:
            PopulationService(){
                this->thisInstance = this;
            };
            ~PopulationService(){};
    };
} // business

#endif



