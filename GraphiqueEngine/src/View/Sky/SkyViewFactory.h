#ifndef SKYVIEW_FACTORY_H
#define SKYVIEW_FACTORY_H

#include "SkyView.h"

namespace graphique
{
    class SkyViewFactory
    {
        public:
            static ISkyView* createEntity(irr::IrrlichtDevice *device, business::ISkyEntity *skyEntity) {
                TMap<EACTIONEVENT, sky::IAction>* keyMap = new TMap<EACTIONEVENT, sky::IAction>();
                keyMap->addElement(EACTIONEVENT_CHANGE_SKY, new sky::ChangeSky());
                return new SkyView(device, skyEntity, keyMap);
            }
    };
} // graphique

#endif
