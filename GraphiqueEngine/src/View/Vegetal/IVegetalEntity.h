#ifndef IVEGETALVIEW_H
#define IVEGETALVIEW_H

#include <irrlicht.h>

#include "../../Business/IVegetalEntity.h"

namespace graphique
{
    class IVegetalView
    {
    public:
        IVegetalView(){};
        virtual ~IVegetalView(){};

        virtual bool draw()=0;
    };
} // graphique

#endif

