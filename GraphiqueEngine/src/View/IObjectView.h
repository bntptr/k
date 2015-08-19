#ifndef IOBJECTVIEW_H
#define IOBJECTVIEW_H

#include "../Business/Event/EActionEvent.h"

namespace graphique
{
    class IObjectView
    {
    public:
        IObjectView(){};
        virtual ~IObjectView(){};

        virtual bool oneEvent(EACTIONEVENT event)=0;
    };
} // graphique

#endif


