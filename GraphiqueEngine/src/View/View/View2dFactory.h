#ifndef VIEW_2D_FACTORY_H
#define VIEW_2D_FACTORY_H

#include "View2d.h"

namespace graphique
{
    class View2dFactory
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
                return new View2d(keyMap);
            }

            static IView* createEntity(IView *view) {
                TMap<EVIEW, IAction>* keyMap = new TMap<EVIEW, IAction>();
                keyMap->addElement(EVIEW_CLOSE_WINDOWS, new CloseWindows());
                keyMap->addElement(EVIEW_MODE_2D, new Mode2d());
                keyMap->addElement(EVIEW_MODE_FPS, new ModeFPS());
                keyMap->addElement(EVIEW_MODE_RTS, new ModeRTS());
                keyMap->addElement(EVIEW_MODE_RPG, new ModeRPG());
                keyMap->addElement(EVIEW_MODE_EDITOR, new ModeEditor());
                return new View2d(keyMap, view);
            }
        };
} // graphique

#endif


