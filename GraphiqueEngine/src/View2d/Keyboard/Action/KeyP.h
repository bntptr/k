#ifndef IACTIONKEY_P_H
#define IACTIONKEY_P_H

#include "IKey.h"

#include "../../Selector/ISelectorService.h"

namespace graphique
{
    class KeyP : public IKey
    {
        public:
            KeyP(){};
            virtual ~KeyP(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif

