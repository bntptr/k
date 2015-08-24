#ifndef VIEW_TERRAIN_IACTION_H
#define VIEW_TERRAIN_IACTION_H

#include "../ITerrainView.h"

namespace graphique
{
    namespace terrain
    {
        class IAction
        {
            public:
                IAction(){};
                virtual ~IAction(){};

                virtual int execute(ITerrainView *sky) {
                    return -1;
                };
        };
    } // terrain
} // graphique

#endif


