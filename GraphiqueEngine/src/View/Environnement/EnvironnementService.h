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
            EnvironnementService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->environnement = EnvironnementFactory::createEntity(device);
            };
            ~EnvironnementService(){};

            bool draw() {
                return this->environnement->draw();
            }

            bool oneEvent(const irr::SEvent& event) {
                return this->environnement->oneEvent(event);
            }
    };
} // business

#endif



