#ifndef IACTIONKEY_H
#define IACTIONKEY_H

#include "../IView.h"

namespace graphique
{
    class IActionKey
    {
        public:
            IActionKey(){};
            virtual ~IActionKey(){};

            virtual int execute(IView *view)=0;
    };
} // graphique

#endif
