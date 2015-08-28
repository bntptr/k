#ifndef VIEW_POPULATION_SERVICE_H
#define VIEW_POPULATION_SERVICE_H

#include "PopulationViewFactory.h"
#include "IPopulationService.h"

namespace graphique
{
    class PopulationService : public IPopulationService
    {
        protected:
            IPopulationService* thisInstance;
            IPopulationView *population;

        public:
            PopulationService(
                irr::IrrlichtDevice *device,
                business::IPopulationEntity *populationEntity
            ){
                this->thisInstance = this;
                this->population = PopulationViewFactory::createEntity(device, populationEntity);
            };
            ~PopulationService(){};

            IObjectView* getObjectViewFromId(int id) {
                return this->population->getObjectViewFromId(id);
            }

            bool build() {
                return this->population->build();
            }

            bool draw() {
                return this->population->draw();
            }

            bool addCharacter(
                irr::IrrlichtDevice *device,
                business::ICharacterEntity *characterEntity
            ){
                return this->population->addCharacter(device, characterEntity);
            }

            bool drawAll() {
                return this->population->drawAll();
            }

            IObjectView* getCharacterFromPlayer(){
                return this->population->getCharacterFromPlayer();
            }

            IPopulationView* getPopulationView() {
                return this->population;
            }
    };
} // business

#endif



