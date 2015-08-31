#ifndef VIEW_ENVIRONNEMENT_FACTORY_H
#define VIEW_ENVIRONNEMENT_FACTORY_H

#include "Environnement.h"

namespace graphique
{
    class EnvironnementFactory
    {
        public:
            static IEnvironnement* createEntity(irr::IrrlichtDevice *device) {
                return new Environnement(device);
            }
    };
} // graphique

#endif

