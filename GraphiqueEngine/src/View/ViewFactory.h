#ifndef VIEW_FACTORY_H
#define VIEW_FACTORY_H

#include <irrlicht.h>
#include "View.h"
#include "Action/Actions.h"

namespace graphique
{
    class ViewFactory
    {
        public:
            static IView* createEntity() {
                TMap<EVIEW, IAction>* keyMap = new TMap<EVIEW, IAction>();
                keyMap->addElement(EVIEW_CLOSE_WINDOWS, new CloseWindows());
                keyMap->addElement(EVIEW_MODE_2D, new Mode2d());
                keyMap->addElement(EVIEW_MODE_FPS, new ModeFPS());
                keyMap->addElement(EVIEW_MODE_RTS, new ModeRTS());
                keyMap->addElement(EVIEW_MODE_RPG, new ModeRPG());
                keyMap->addElement(EVIEW_MODE_EDITOR, new ModeEditor());
                return new View(keyMap);
            }
        };
} // graphique

#endif


