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
                switch(view->getMode())
                {
                    case EVIEW_MODE_EDITOR:
                        view->onEvent(EVIEW_MODE_2D);
                        break;
                    case EVIEW_MODE_2D:
                        view->onEvent(EVIEW_MODE_FPS);
                        break;
                    case EVIEW_MODE_FPS:
                        view->onEvent(EVIEW_MODE_RTS);
                        break;
                    case EVIEW_MODE_RTS:
                        view->onEvent(EVIEW_MODE_RPG);
                        break;
                    case EVIEW_MODE_RPG:
                        view->onEvent(EVIEW_MODE_EDITOR);
                        break;
                    default:
                        view->onEvent(EVIEW_MODE_EDITOR);
                        break;
                }
                return 0;
            }

            int executePressed(IView *view) {
                return 0;
            }
    };
} // graphique

#endif



