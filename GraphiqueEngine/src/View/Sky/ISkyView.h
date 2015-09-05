#ifndef VIEW_ISKY_VIEW_H
#define VIEW_ISKY_VIEW_H

#include <irrlicht.h>

#include "../SceneNode/ISceneNodeService.h"
#include "../../Business/Sky/ISkyEntity.h"

namespace graphique
{
    class ISkyView
    {
        public:
            ISkyView(){};
            virtual ~ISkyView(){};

            virtual ISceneNode* getSkyBox()=0;
            virtual ISceneNode* getSkyDome()=0;
            virtual bool getShowBox()=0;
            virtual bool setShowBox(bool showBox)=0;
            virtual bool build()=0;
            virtual bool draw()=0;
            virtual bool onEvent(EACTIONEVENT event)=0;

            virtual business::ISkyEntity* getSkyEntity()=0;
    };
} // graphique

#endif
