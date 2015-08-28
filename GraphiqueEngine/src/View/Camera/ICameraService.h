#ifndef VIEW_ICAMERA_SERVICE_H
#define VIEW_ICAMERA_SERVICE_H

#include "ICamera.h"

namespace graphique
{
    class ITerrainService;
    class IPopulationService;
    class ICameraService
    {
        public:
            ICameraService(){};
            virtual ~ICameraService(){};

            virtual irr::scene::ICameraSceneNode* getCameraSceneNode()=0;
            virtual bool build()=0;
            virtual bool draw(ITerrainService *terrain, IPopulationService *population)=0;

            virtual bool active2d()=0;
            virtual bool activeFPS()=0;
            virtual bool activeRTS()=0;
            virtual bool activeRPG()=0;
            virtual bool activeEditor()=0;
    };
}

#endif



