#ifndef VIEW_ITERRAIN_SERVICE_H
#define VIEW_ITERRAIN_SERVICE_H

#include "../../Kutility/kutility.h"

#include "ITerrainView.h"

#include "../Camera/ICameraService.h"

namespace graphique
{
    class ITerrainService
    {
        public:
            ITerrainService(){};
            virtual ~ITerrainService(){};

            virtual irr::scene::ITerrainSceneNode* getTerrainSceneNode()=0;
            virtual bool build(ICameraService* camera)=0;
            virtual bool draw(business::Vector3d position, business::Vector3d scale)=0;
            virtual bool onEvent(EACTIONEVENT event)=0;

            virtual ITerrainView* getTerrainView()=0;
    };
}

#endif




