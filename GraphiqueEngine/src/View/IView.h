#ifndef IVIEW_H
#define IVIEW_H
//#include "ViewInterface.h"
#include "../Business/BusinessInterface.h"
#include "Selector/SelectorService.h"
#include "Environnement/IEnvironnement.h"
#include "Cursor/ICursorEntity.h"
#include "Keyboard/IKeyboard.h"
#include "Camera/ICamera.h"
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
            virtual int runExemple()=0;

            virtual SelectorService* getSelector()=0;
            virtual IEnvironnement *getEnvironnement()=0;
            virtual ICursorEntity *getCursor()=0;
            virtual IKeyboard *getKeyboard()=0;
            virtual ICamera *getCamera()=0;
            virtual ITerrainView *getTerrain()=0;
            virtual ISkyView *getSky()=0;
            virtual IPopulationView *getPopulation()=0;
            virtual IBuildingEntity *getBuilding()=0;
    };

} // graphique

#endif
