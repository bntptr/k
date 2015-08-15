#ifndef IBUILDINGVIEW_H
#define IBUILDINGVIEW_H

#include <irrlicht.h>

//#include "../../Business/IBuildingEntity.h"

namespace graphique
{
    class IBuildingView
    {
        public:
            IBuildingView(){};
            virtual ~IBuildingView(){};

            virtual bool draw()=0;
    };
} // graphique

#endif

