#ifndef IVIEW_H
#define IVIEW_H
//#include "ViewInterface.h"
#include "../Business/BusinessInterface.h"
#include "Selector/ISelectorService.h"
#include "Environnement/IEnvironnementService.h"
#include "Cursor/ICursorEntity.h"
#include "Keyboard/IKeyboardService.h"
#include "Camera/ICameraService.h"
#include "Terrain/ITerrainView.h"
#include "Sky/ISkyView.h"
#include "Population/IPopulationView.h"
#include "Building/IBuildingEntity.h"

namespace graphique
{
    class IView //: public ViewInterface
    {
        public:
            IView(){};
            ~IView(){};

            virtual int error()=0;
            virtual int init()=0;
            virtual int build(business::BusinessInterface *business)=0;
            virtual int run()=0;

            virtual ISelectorService* getSelector()=0;
            virtual IEnvironnementService *getEnvironnementService()=0;
            virtual ICursorEntity *getCursor()=0;
            virtual IKeyboardService *getKeyboardService()=0;
            virtual ICameraService *getCameraService()=0;
            virtual ITerrainView *getTerrain()=0;
            virtual ISkyView *getSky()=0;
            virtual IPopulationView *getPopulation()=0;
            virtual IBuildingEntity *getBuilding()=0;
    };

} // graphique

#endif
