#ifndef IACTIONKEY_Q_H
#define IACTIONKEY_Q_H

#include "IKey.h"

namespace graphique
{
    class KeyQ : public IKey
    {
        public:
            KeyQ(){};
            virtual ~KeyQ(){};

            int execute(IView *view) {
                ITerrainService* terrain = view->getTerrain();
                terrain->onEvent(EACTIONEVENT_TERRAIN_MAP_TRIANGLE);
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


