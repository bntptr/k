#ifndef ITERRAINVIEW_H
#define ITERRAINVIEW_H

#include <irrlicht.h>

#include "../../Kutility/kutility.h"

#include "../../Business/Ground/IGroundEntity.h"
#include "../Camera/ICameraService.h"

namespace graphique
{
    class ITerrainView
    {
        public:
            ITerrainView(){};
            virtual ~ITerrainView(){};

            virtual irr::scene::ITerrainSceneNode* getTerrain()=0;
            virtual bool build(ICameraService* camera)=0;
            virtual bool draw(business::Vector3d position, business::Vector3d scale)=0;
            virtual bool onEvent(EACTIONEVENT event)=0;

            virtual business::IGroundEntity* getGroundEntity()=0;
    };
} // graphique

#endif
