#ifndef ICAMERA_SERVICE_H
#define ICAMERA_SERVICE_H

#include "ICamera.h"

namespace graphique
{
    class ICameraService
    {
        public:
            ICameraService(){};
            virtual ~ICameraService(){};

            // renommer getCameraSceneNode
            virtual irr::scene::ICameraSceneNode* getCamera()=0;
            virtual bool build()=0;
            virtual bool draw()=0;
    };
}

#endif



