#ifndef IACTIONKEY_W_H
#define IACTIONKEY_W_H

#include <irrlicht.h>

#include "IKey.h"

#include "../../Selector/ISelectorService.h"

namespace graphique
{
    class KeyW : public IKey
    {
        public:
            KeyW(){};
            virtual ~KeyW(){};

            int execute(IView *view) {
                return 0;
            }

            int executePressed(IView *view) {
                ISelectorService* selector = view->getSelector();
                selector->onEventSelectorLeft(EACTIONEVENT_DEPLACE_X);

/* A gérer via Business
                if (view->getKeyboardService()->isDown(irr::KEY_KEY_C)) {
                    view->getKeyboardService()->executePressed(irr::KEY_KEY_C);
                } else {
                }*/
                return 0;
            }
    };
} // graphique

#endif

