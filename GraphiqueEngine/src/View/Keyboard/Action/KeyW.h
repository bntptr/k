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
                selector->oneEventSelectorLeft(EACTIONEVENT_DEPLACE_X);

                if (view->getKeyboardService()->isDown(irr::KEY_KEY_C)) {
                std::cout << "ça marche !!!" << std::endl;
                std::cout << "ça marche !!!" << std::endl;
                std::cout << "ça marche !!!" << std::endl;
                    view->getKeyboardService()->executePressed(irr::KEY_KEY_C);
                } else {

                std::cout << "ça PAS !!!" << std::endl;
                std::cout << "ça PAS !!!" << std::endl;
                std::cout << "ça PAS !!!" << std::endl;
                }
                return 0;
            }
    };
} // graphique

#endif

