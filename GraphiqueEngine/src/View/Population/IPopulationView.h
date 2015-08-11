#ifndef IPOPULATIONVIEW_H
#define IPOPULATIONVIEW_H

#include <list>
#include <irrlicht.h>

#include "../../Business/Population/IPopulationEntity.h"
#include "Characters/ICharacter.h"

namespace graphique
{
    class IPopulationView
    {
    public:
        IPopulationView(){};
        virtual ~IPopulationView(){};

        virtual bool build()=0;
        virtual bool draw()=0;
        virtual bool drawAll()=0;

        virtual bool addCharacter(
            irr::IrrlichtDevice *device,
            ICharacterEntity *characterEntity
        )=0;

        virtual IObjectView* getCharacterFromPlayer()=0;

    };
} // graphique

#endif
