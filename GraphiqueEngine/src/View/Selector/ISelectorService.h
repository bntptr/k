#ifndef ISELECTOR_SERVICE_H
#define ISELECTOR_SERVICE_H

#include "../IObjectView.h"
//#include "../IView.h"

#include "ISelectorEntity.h"

namespace graphique
{
    class IView;

    class ISelectorService
    {
        public:
            ISelectorService(){};
            virtual ~ISelectorService(){};

            virtual ISelectorEntity* getCursorLeft()=0;

            virtual ISelectorEntity* getCursorRight()=0;

            virtual ISelectorService* resetCursorLeft()=0;

            virtual ISelectorService* resetCursorRight()=0;

            virtual ISelectorService* addToCursorLeft(IObjectView *obj)=0;

            virtual ISelectorService* addToCursorRight(IObjectView *obj)=0;

            virtual ISelectorService* selectLeft(IView *view)=0;

            virtual ISelectorService* oneEventSelectorRight(EACTIONEVENT event)=0;

            virtual ISelectorService* oneEventSelectorLeft(EACTIONEVENT event)=0;
    };
} // business

#endif

