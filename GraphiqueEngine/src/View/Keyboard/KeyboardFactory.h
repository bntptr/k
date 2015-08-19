#ifndef KEYBOARD_FACTORY_H
#define KEYBOARD_FACTORY_H

#include <irrlicht.h>
#include "Keyboard.h"
#include "Action/Actions.h"

namespace graphique
{
    class KeyboardFactory
    {
        public:
            static IKeyboard* createEntity(IView *view) {
                TMap<irr::EKEY_CODE, IKey>* keyMap = new TMap<irr::EKEY_CODE, IKey>();
                keyMap->addElement(irr::KEY_KEY_D, new KeyD());
                keyMap->addElement(irr::KEY_KEY_F, new KeyF());
                keyMap->addElement(irr::KEY_KEY_Q, new KeyQ());
                keyMap->addElement(irr::KEY_KEY_S, new KeyS());
                keyMap->addElement(irr::KEY_KEY_W, new KeyW());
                return new Keyboard(view, keyMap);
            }
        };
} // graphique

#endif

