#ifndef PLAYERVIEW_FACTORY_H
#define PLAYERVIEW_FACTORY_H

#include "PlayerView.h"

namespace graphique
{
    class PlayerViewFactory
    {
    public:
        static IPlayerView* createEntity(irr::IrrlichtDevice *device) {
            return new PlayerView(device);
        }
    };
} // graphique

#endif

