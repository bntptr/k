#ifndef IVIEW_H
#define IVIEW_H

#include "../Action/EGraphique.h"
#include "Action/EView.h"
#include "../Business/BusinessInterface.h"
#include "Selector/ISelectorService.h"
#include "Environnement/IEnvironnementService.h"
#include "Cursor/ICursorService.h"
#include "Keyboard/IKeyboardService.h"
#include "Camera/ICameraService.h"
#include "Terrain/ITerrainService.h"
#include "Sky/ISkyService.h"
#include "Population/IPopulationService.h"
#include "Building/IBuildingService.h"

namespace graphique
{
    class IView
    {
        public:
            IView(){};
            ~IView(){};

            virtual int error()=0;
            virtual int init()=0;
            virtual int build(business::BusinessInterface *business)=0;
            virtual EGRAPHIQUE run()=0;
            virtual int exit()=0;
            virtual int exit(EGRAPHIQUE event)=0;
            virtual int drop()=0;
            virtual EVIEW getMode()=0;

            virtual IView* execute(EVIEW key)=0;
            virtual bool onEvent(EVIEW event)=0;

            virtual ISelectorService* getSelector()=0;
            virtual IEnvironnementService *getEnvironnementService()=0;
            virtual ICursorService *getCursorService()=0;
            virtual IKeyboardService *getKeyboardService()=0;
            virtual ICameraService *getCameraService()=0;
            virtual ITerrainService *getTerrainService()=0;
            virtual ISkyService *getSkyService()=0;
            virtual IPopulationService *getPopulationService()=0;
            virtual IBuildingService *getBuildingService()=0;
    };
} // graphique

#endif
