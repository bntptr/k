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
            virtual bool draw()=0;
            virtual bool buildAll()=0;
            virtual bool drawAll()=0;

            virtual bool addCharacter(
                irr::IrrlichtDevice *device,
                business::ICharacterEntity *characterEntity
            )=0;

            virtual IObjectView* getCharacterFromPlayer()=0;
            virtual IObjectView* getObjectViewFromId(int id)=0;

            virtual IPopulationView* getPopulationView()=0;
    };
}

#endif




