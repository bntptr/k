#ifndef ITERRAINVIEW_H
#define ITERRAINVIEW_H

#include <irrlicht.h>

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
            virtual bool draw(ICameraService* camera)=0;
            virtual bool oneEvent(EACTIONEVENT event)=0;
    };
} // graphique

#endif
