#ifndef EVENTRECEIVER_FACTORY_H
#define EVENTRECEIVER_FACTORY_H

#include "ViewEventReceiver.h"

namespace graphique
{
    class EventReceiverFactory
    {
    public:
        static ViewEventReceiver* createEntity(irr::IrrlichtDevice *device) {
            return new ViewEventReceiver(device);
        }
    };
} // graphique

#endif
