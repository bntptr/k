#ifndef VIEW_ICURSOR_ENTITY_H
#define VIEW_ICURSOR_ENTITY_H

#include <irrlicht.h>
#include "../Camera/ICamera.h"

namespace graphique
{
    class ICursorEntity
    {
        public:
            ICursorEntity(){};
            virtual ~ICursorEntity(){};

            virtual bool build()=0;
            virtual bool draw()=0;
            virtual bool oneEvent(EACTIONEVENT event)=0;
            virtual scene::ITriangleSelector* getSelector()=0;

            virtual ICursorEntity* setCamera(ICamera *camera)=0;
    };
} // graphique

#endif


