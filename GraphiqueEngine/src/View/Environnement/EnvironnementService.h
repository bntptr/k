#ifndef VIEW_ENVIRONNEMENT_SERVICE_H
#define VIEW_ENVIRONNEMENT_SERVICE_H

#include "Item/BarMenu.h"
#include "IEnvironnementService.h"
#include "EnvironnementFactory.h"

namespace graphique
{
    class EnvironnementService : public IEnvironnementService
    {
        protected:
            IEnvironnementService* thisInstance;
            IEnvironnement *environnement;

        public:
            EnvironnementService(){
                this->thisInstance = this;
            };
            EnvironnementService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->environnement = EnvironnementFactory::createEntity(device);
            };
            ~EnvironnementService(){};

            bool build() {
                return this->environnement->build();
            }

            bool onEvent(const irr::SEvent& event) {
                return this->environnement->onEvent(event);
            }
    };
} // business

#endif



