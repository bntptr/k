#ifndef IACTIONKEY_D_H
#define IACTIONKEY_D_H

#include "IKey.h"

namespace graphique
{
    class KeyD : public IKey
    {
        public:
            KeyD(){};
            virtual ~KeyD(){};

            int execute(IView *view) {
                ITerrainService* terrain = view->getTerrain();
                terrain->oneEvent(EACTIONEVENT_TERRAIN_MAP_DETAIL);
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif

