#ifndef VIEW_ITERRAIN_SERVICE_H
#define VIEW_ITERRAIN_SERVICE_H

#include "ITerrainView.h"

namespace graphique
{
    class ITerrainService
    {
        public:
            ITerrainService(){};
            virtual ~ITerrainService(){};

            virtual irr::scene::ITerrainSceneNode* getTerrain()=0;
            virtual bool build(ICameraService* camera)=0;
            virtual bool draw(ICameraService* camera)=0;
            virtual bool onEvent(EACTIONEVENT event)=0;
    };
}

#endif




