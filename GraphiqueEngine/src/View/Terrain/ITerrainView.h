#ifndef ITERRAINVIEW_H
#define ITERRAINVIEW_H

#include <irrlicht.h>

#include "../../Business/IGroundEntity.h"
#include "../Camera/ICamera.h"

namespace graphique
{
    class ITerrainView
    {
    public:
        ITerrainView(){};
        virtual ~ITerrainView(){};

        virtual scene::ITerrainSceneNode* getTerrain()=0;
        virtual bool draw(ICamera* camera)=0;
    };
} // graphique

#endif
