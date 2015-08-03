#ifndef IPOPULATIONVIEW_H
#define IPOPULATIONVIEW_H

#include <irrlicht.h>

#include "../../Business/IPopulationEntity.h"

namespace graphique
{
    class IPopulationView
    {
    public:
        IPopulationView(){};
        virtual ~IPopulationView(){};

        virtual bool draw()=0;
    };
} // graphique

#endif
