#ifndef VIEW_ISKY_SERVICE_H
#define VIEW_ISKY_SERVICE_H

#include "ISkyView.h"

namespace graphique
{
    class ISkyService
    {
        public:
            ISkyService(){};
            virtual ~ISkyService(){};

            virtual irr::scene::ISceneNode* getSkyBox()=0;
            virtual irr::scene::ISceneNode* getSkyDome()=0;
            virtual bool getShowBox()=0;
            virtual bool setShowBox(bool showBox)=0;
            virtual bool build()=0;
            virtual bool draw()=0;
            virtual bool onEvent(EACTIONEVENT event)=0;

            virtual ISkyView* getSkyView()=0;
    };
}

#endif




