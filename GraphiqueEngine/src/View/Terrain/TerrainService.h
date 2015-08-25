#ifndef VIEW_TERRAIN_SERVICE_H
#define VIEW_TERRAIN_SERVICE_H

#include "CursorEntity.h"
#include "ITerrainService.h"

namespace graphique
{
    class TerrainService : public ITerrainService
    {
        protected:
            ITerrainService* thisInstance;

        public:
            TerrainService(){
                this->thisInstance = this;
            };
            ~TerrainService(){};
    };
} // business

#endif



