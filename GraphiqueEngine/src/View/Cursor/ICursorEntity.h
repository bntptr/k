#ifndef VIEW_ICURSOR_ENTITY_H
#define VIEW_ICURSOR_ENTITY_H

#include <irrlicht.h>

namespace graphique
{
    class ICursorEntity
    {
        public:
            ICursorEntity(){};
            virtual ~ICursorEntity(){};

            virtual bool draw()=0;
            virtual bool oneEvent(EACTIONEVENT event)=0;
            virtual scene::ITriangleSelector* getSelector()=0;
    };
} // graphique

#endif


