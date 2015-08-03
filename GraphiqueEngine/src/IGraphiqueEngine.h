#ifndef IGRAPHIQUEENGINE_H
#define IGRAPHIQUEENGINE_H

//#include <IEngine.h>
#include "Business/BusinessInterface.h"
#include "View/IView.h"

namespace graphique
{
    class IGraphiqueEngine// : public IEngine
    {
        public:
            IGraphiqueEngine() {};
            virtual ~IGraphiqueEngine(){};

            virtual bool start()=0;
            virtual bool run()=0;
            virtual bool exit()=0;
            virtual bool drop()=0;

            virtual BusinessInterface* getBusiness()=0;
            virtual IGraphiqueEngine* setBusiness(BusinessInterface *business)=0;
            virtual IView* getView()=0;
            virtual IGraphiqueEngine* setView(IView *view)=0;
    };
}
#endif // IGRAPHIQUEENGINE_H
