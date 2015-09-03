#ifndef VIEW_2D_H
#define VIEW_2D_H

#include <irrlicht.h>

#include "../View/View.h"
#include "Action/Actions.h"
#include "Cursor/Cursor2dServiceFactory.h"
#include "Keyboard/Keyboard2dServiceFactory.h"
#include "Camera/Camera2dServiceFactory.h"
#include "Environnement/Environnement2dServiceFactory.h"

namespace graphique
{
    class View2d : public View
    {
        public:
            View2d(TMap<EVIEW, IAction>* keyMap) : View(keyMap) {}
            View2d(TMap<EVIEW, IAction>* keyMap, IView *view) : View(keyMap, view){
                this->thisInstance = this;
                this->keyMap = keyMap;
                this->selector = new SelectorService();
                this->mode = EVIEW_MODE_2D;

                this->terrain = TerrainServiceFactory::createService(
                    this->device,
                    view->getTerrainService()->getTerrainView()->getGroundEntity()
                );

                this->sky = SkyServiceFactory::createService(
                    this->device,
                    view->getSkyService()->getSkyView()->getSkyEntity()
                );

                this->population = PopulationServiceFactory::createService(
                    this->device,
                    view->getPopulationService()->getPopulationView()->getPopulationEntity()
                );

                this->building = BuildingServiceFactory::createService(
                    this->sceneNodeService,
                    view->getBuildingService()->getBuildingView()->getBuildingEntity()
                );
            }
            ~View2d(){};

            /**
             * Construction de tous les éléments de la scène graphique
             */
            int build(business::BusinessInterface *business) {
                std::cout <<"build view2d !" << std::endl;
                business::IBusinessEntity *entity = business->loadBusinessEntity();

                this->cursor = Cursor2dServiceFactory::createService(this->device, this);

                this->keyboard = Keyboard2dServiceFactory::createService(this);

                this->environnement = Environnement2dServiceFactory::createService(this->device);
                this->environnement->build();

                this->camera = Camera2dServiceFactory::createService(this->device, this->cursor);
                this->camera->build();

                this->cursor->setCameraService(this->camera);

                this->buildGame(business);
                return 0;
            }

            /**
             * Construction de tous les éléments de la scène graphique
             * Si on ne récupère pas le buildGame de la View d'avant cela n'a plus de sens [28/08/2015]
             */
            int buildGame(business::BusinessInterface *business) {
                std::cout << "build game 2d !" << std::endl;
                business::IBusinessEntity *entity = business->loadBusinessEntity();

                business::IGroundEntity *ground = entity->getGround();
                this->terrain = TerrainServiceFactory::createService(this->device, ground);

                business::ISkyEntity *skyEntity = entity->getSky();
                this->sky = SkyServiceFactory::createService(this->device, skyEntity);

                business::IPopulationEntity *populationEntity = entity->getPopulation();
                this->population = PopulationServiceFactory::createService(this->device, populationEntity);
                this->population->build();

                business::IBuildingEntity *buildingEntity = entity->getBuilding();
                this->building = BuildingServiceFactory::createService(
                    this->sceneNodeService,
                    buildingEntity
                );

                // selection par default pour les tests
                IObjectView *obj = this->population->getCharacterFromPlayer();
                this->selector->addToCursorLeft(obj);
                //business::IPlayerEntity *player = entity->getPlayer();
                return 0;
            }
    };
} // graphique

#endif
