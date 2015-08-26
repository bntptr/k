#ifndef IACTIONKEY_TAB_H
#define IACTIONKEY_TAB_H

#include "IKey.h"

namespace graphique
{
    class KeyTab : public IKey
    {
        public:
            KeyTab(){};
            virtual ~KeyTab(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif



