#ifndef IACTIONKEY_ESCAP_H
#define IACTIONKEY_ESCAP_H

#include "IKey.h"

namespace graphique
{
    class KeyEscap : public IKey
    {
        public:
            KeyEscap(){};
            virtual ~KeyEscap(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif


