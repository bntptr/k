#ifndef VIEW_POPULATION_FPS_VIEW_H
#define VIEW_POPULATION_FPS_VIEW_H

#include "../PopulationView.h"

namespace graphique
{
    class PopulationFPSView : public PopulationView
    {
        protected:
            ICharacter *fpsOne;
            ICharacter *fpsTwo;
            ICharacter *fpsThree;
            ICharacter *fpsFor;

        public:
            PopulationFPSView(irr::IrrlichtDevice *device, business::IPopulationEntity *populationEntity){
                this->thisInstance = this;
                this->device = device;
                this->populationEntity = populationEntity;
                this->characterList = new TList<ICharacter>();
            };
            ~PopulationFPSView(){};
    };
} // graphique

#endif
