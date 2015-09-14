#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include <irrlicht.h>

#include "../View/View.h"
#include "Action/Actions.h"
//#include "Cursor/CursorMenuServiceFactory.h"
//#include "Keyboard/KeyboardMenuServiceFactory.h"
//#include "Camera/CameraMenuServiceFactory.h"
//#include "Environnement/EnvironnementMenuServiceFactory.h"

namespace graphique
{
    class ViewMenu : public View
    {
        public:
            ViewMenu(TMap<EVIEW, IAction>* keyMap) : View(keyMap) {}
            ViewMenu(TMap<EVIEW, IAction>* keyMap, IView *view) : View(keyMap, view){
                this->mode = EVIEW_MODE_EDITOR;
            }
            ~ViewMenu(){};
    };
} // graphique

#endif


