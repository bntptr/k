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
    };
} // graphique

#endif


