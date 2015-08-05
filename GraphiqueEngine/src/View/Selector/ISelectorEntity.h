#ifndef ISELECTORENTITY_H
#define ISELECTORENTITY_H

#include <irrlicht.h>

#include "../IObjectView.h"

namespace graphique
{
    class ISelectorEntity
    {
    public:
        ISelectorEntity(){};
        virtual ~ISelectorEntity(){};

        virtual ISelectorEntity* add(IObjectView *object)=0;
        virtual ISelectorEntity* reset()=0;
    };
} // graphique

#endif

