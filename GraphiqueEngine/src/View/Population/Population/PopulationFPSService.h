#ifndef VIEW_POPULATION_FPS_SERVICE_H
#define VIEW_POPULATION_FPS_SERVICE_H

#include "../PopulationService.h"

namespace graphique
{
    class PopulationFPSService : public PopulationService
    {
        public:
            PopulationFPSService(
                irr::IrrlichtDevice *device,
                business::IPopulationEntity *populationEntity
            ){
                this->thisInstance = this;
                this->population = PopulationViewFactory::createEntity(device, populationEntity);
            };
            ~PopulationFPSService(){};


            bool activeFPS(IObjectView *firstObjectView) {
                std::cout << "population active FPS" << std::endl;
                irr::scene::ISceneManager* smgr = device->getSceneManager();
                this->camera = this->cameraFPS;
                this->cameraFPS->getCameraSceneNode()->setVisible(true);
                smgr->setActiveCamera(this->cameraFPS->getCameraSceneNode());
                return true;
            }
    };
} // business

#endif



