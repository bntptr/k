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

        virtual bool draw()=0;
    };
} // graphique

#endif
