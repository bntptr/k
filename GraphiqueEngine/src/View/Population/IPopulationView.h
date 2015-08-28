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

            virtual bool loadCharacterList()=0;
            virtual bool build()=0;
            virtual bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale)=0;
            virtual bool buildAll()=0;
            virtual bool drawAll(business::Vector3d cameraPosition, business::Vector3d cameraScale)=0;

            virtual bool addCharacter(
                irr::IrrlichtDevice *device,
                business::ICharacterEntity *characterEntity
            )=0;

            virtual IObjectView* getCharacterFromPlayer()=0;
            virtual IObjectView* getObjectViewFromId(int id)=0;

            virtual business::IPopulationEntity* getPopulationEntity()=0;
    };
} // graphique

#endif
