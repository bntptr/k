#ifndef VIEW_IPOPULATION_SERVICE_H
#define VIEW_IPOPULATION_SERVICE_H

#include "PopulationView.h"

namespace graphique
{
    class IPopulationService
    {
        public:
            IPopulationService(){};
            virtual ~IPopulationService(){};

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

            virtual IPopulationView* getPopulationView()=0;
            virtual bool activeFPS(IObjectView *firstObjectView)=0;
    };
}

#endif




