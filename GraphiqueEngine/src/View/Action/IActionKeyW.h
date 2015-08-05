#ifndef IACTIONKEYW_H
#define IACTIONKEYW_H

#include "IActionKey.h"

namespace graphique
{
    class IActionKeyW : public IActionKey
    {
        public:
            IActionKeyW(){};
            virtual ~IActionKeyW(){};

            int execute(IView *view) {
            }
    };
} // graphique

#endif

