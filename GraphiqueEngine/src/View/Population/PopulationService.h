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
                ISceneNodeService *sceneNodeService,
                business::IPopulationEntity *populationEntity
            ){
                this->thisInstance = this;
                this->population = PopulationViewFactory::createEntity(sceneNodeService, populationEntity);
            };
            ~PopulationService(){};

            IObjectView* getObjectViewFromId(int id) {
                return this->population->getObjectViewFromId(id);
            }

            bool build() {
                return this->population->build();
            }

            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                return this->population->draw(cameraPosition, cameraScale);
            }

            bool addCharacter(
                business::ICharacterEntity *characterEntity
            ){
                return this->population->addCharacter(characterEntity);
            }

            /**
             * Non utilisé à ce niveau
             */
            bool buildAll() {
                return this->population->buildAll();
            }

            /**
             * Non utilisé à ce niveau
             */
            bool drawAll(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                return this->population->drawAll(cameraPosition, cameraScale);
            }

            IObjectView* getCharacterFromPlayer(){
                return this->population->getCharacterFromPlayer();
            }

            IPopulationView* getPopulationView() {
                return this->population;
            }

            bool activeFPS(IObjectView *firstObjectView) {
                std::cout << "population active FPS" << std::endl;
                return true;
            }
    };
} // business

#endif



