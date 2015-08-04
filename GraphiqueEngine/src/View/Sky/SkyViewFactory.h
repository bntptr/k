#ifndef SKYVIEW_FACTORY_H
#define SKYVIEW_FACTORY_H

#include "SkyView.h"

namespace graphique
{
    class SkyViewFactory
    {
    public:
        static ISkyView* createEntity() {
            return new SkyView();
        }
    };
} // graphique

#endif

