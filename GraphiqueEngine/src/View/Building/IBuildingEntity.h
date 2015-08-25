#ifndef VIEW_IBUILDING_ENTITY_H
#define VIEW_IBUILDING_ENTITY_H

#include <irrlicht.h>

//#include "../../Business/IBuildingEntity.h"

namespace graphique
{
    class IBuildingEntity
    {
        public:
            IBuildingEntity(){};
            virtual ~IBuildingEntity(){};

            virtual bool draw()=0;
            virtual bool oneEvent(EACTIONEVENT event)=0;
    };
} // graphique

#endif

