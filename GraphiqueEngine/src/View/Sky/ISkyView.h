#ifndef ISKYVIEW_H
#define ISKYVIEW_H

#include <irrlicht.h>

#include "../../Business/Sky/ISkyEntity.h"

namespace graphique
{
    class ISkyView
    {
        public:
            ISkyView(){};
            virtual ~ISkyView(){};

            virtual irr::scene::ISceneNode* getSkyBox()=0;
            virtual irr::scene::ISceneNode* getSkyDome()=0;
            virtual bool getShowBox()=0;
            virtual bool setShowBox(bool showBox)=0;
            virtual bool draw()=0;
            virtual bool onEvent(EACTIONEVENT event)=0;
    };
} // graphique

#endif
