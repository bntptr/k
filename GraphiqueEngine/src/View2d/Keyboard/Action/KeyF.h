#ifndef IACTIONKEY_F_H
#define IACTIONKEY_F_H

#include "IKey.h"

namespace graphique
{
    class KeyF : public IKey
    {
        public:
            KeyF(){};
            virtual ~KeyF(){};

            int execute(IView *view) {
                ITerrainService* terrain = view->getTerrainService();
                terrain->onEvent(EACTIONEVENT_TERRAIN_MAP_POINT);
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


