#ifndef IVIEW_H
#define IVIEW_H
//#include "ViewInterface.h"
#include "../Business/BusinessInterface.h"
#include "Selector/SelectorService.h"

namespace graphique
{
    class IView //: public ViewInterface
    {
        public:
            IView(){};
            ~IView(){};

            virtual int error()=0;
            virtual int init()=0;
            virtual int build(business::BusinessInterface *business)=0;
            virtual int run()=0;
            virtual int runExemple()=0;

            virtual SelectorService* getSelector()=0;
    };

} // graphique

#endif
