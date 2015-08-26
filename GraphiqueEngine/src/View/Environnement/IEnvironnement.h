#ifndef IENVIRONNEMENT_H
#define IENVIRONNEMENT_H

#include <irrlicht.h>

namespace graphique
{
    class IEnvironnement
    {
        public:
            IEnvironnement(){};
            virtual ~IEnvironnement(){};

            virtual bool build()=0;
            virtual bool onEvent(const irr::SEvent& event)=0;
    };
} // graphique

#endif
