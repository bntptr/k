#ifndef VIEW_MENU_FACTORY_H
#define VIEW_MENU_FACTORY_H

#include "ViewMenu.h"

namespace graphique
{
    class ViewMenuFactory
    {
        public:
            static IView* createEntity() {
                TMap<EVIEW, IAction>* keyMap = new TMap<EVIEW, IAction>();
                keyMap->addElement(EVIEW_CLOSE_WINDOWS, new CloseWindows());
                //keyMap->addElement(EVIEW_MODE_EDITOR, new ModeEditor());
                return new ViewMenu(keyMap);
            }
        };
} // graphique

#endif


