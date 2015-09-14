#ifndef VIEW_ENVIRONNEMENT_2D_SERVICE_H
#define VIEW_ENVIRONNEMENT_2D_SERVICE_H

#include "../../View/Environnement/EnvironnementService.h"

namespace graphique
{
    class Environnement2dService : public EnvironnementService
    {
        public:
            Environnement2dService(irr::IrrlichtDevice *device){
                this->thisInstance = this;
                this->environnement = EnvironnementFactory::createEntity(device);
            };
            ~Environnement2dService(){};
    };
} // business

#endif



