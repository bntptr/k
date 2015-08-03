
#ifndef ICAMERA_H
#define ICAMERA_H

#include <irrlicht.h>

namespace graphique
{
    class ICamera
    {
    public:
        ICamera(){};
        virtual ~ICamera(){};

        virtual scene::ICameraSceneNode* getCamera()=0;
        virtual bool draw()=0;
    };
} // graphique

#endif
