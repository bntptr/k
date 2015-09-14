#ifndef VIEW_TERRAIN_SERVICE_H
#define VIEW_TERRAIN_SERVICE_H

#include "TerrainViewFactory.h"
#include "ITerrainService.h"

namespace graphique
{
    class TerrainService : public ITerrainService
    {
        protected:
            ITerrainService* thisInstance;
            ITerrainView *terrain;

        public:
            TerrainService(
                ISceneNodeService *service,
                business::IGroundEntity *ground
            ){
                this->thisInstance = this;
                this->terrain = TerrainViewFactory::createEntity(service, ground);
            };
            ~TerrainService(){};

            bool build(ICameraService* camera) {
                return this->terrain->build(camera);
            }

            bool draw(business::Vector3d position, business::Vector3d scale) {
                return this->terrain->draw(position, scale);
            }

            bool onEvent(EACTIONEVENT event) {
                return this->terrain->onEvent(event);
            }

            ITerrainView* getTerrainView() {
                return this->terrain;
            }
    };
} // business

#endif



