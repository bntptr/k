#ifndef IVIEW_H
#define IVIEW_H
//#include "ViewInterface.h"
#include "../Business/BusinessInterface.h"

namespace graphique
{
    class IView //: public ViewInterface
    {
        public:
            IView(){};
            ~IView(){};

            virtual int error()=0;
            virtual int init()=0;
            virtual int build(BusinessInterface *business)=0;
            virtual int run()=0;
            virtual int runExemple()=0;
    };

} // graphique

#endif
