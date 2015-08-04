#ifndef PLAYERVIEW_FACTORY_H
#define PLAYERVIEW_FACTORY_H

#include "PlayerView.h"

namespace graphique
{
    class PlayerViewFactory
    {
    public:
        static IPlayerView* createEntity() {
            return new PlayerView();
        }
    };
} // graphique

#endif

