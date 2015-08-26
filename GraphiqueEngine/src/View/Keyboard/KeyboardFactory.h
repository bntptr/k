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
                //TMap<EKEY, KeyD>* keyMapD = new TMap<EKEY, KeyD>();
                //KeyD kd;// = new KeyD();
                //keyMapD->addElement(EKEY_D, kd);
                TMap<irr::EKEY_CODE, IKey>* keyMap = new TMap<irr::EKEY_CODE, IKey>();
                IKey *k = new KeyD();
                keyMap->addElement(irr::KEY_KEY_D, k);
                keyMap->addElement(irr::KEY_KEY_F, new KeyF());
                keyMap->addElement(irr::KEY_KEY_Q, new KeyQ());
                keyMap->addElement(irr::KEY_KEY_S, new KeyS());
                keyMap->addElement(irr::KEY_KEY_W, new KeyW());
                keyMap->addElement(irr::KEY_KEY_X, new KeyX());
                keyMap->addElement(irr::KEY_KEY_C, new KeyC());
                keyMap->addElement(irr::KEY_KEY_V, new KeyV());
                keyMap->addElement(irr::KEY_KEY_P, new KeyP());
                keyMap->addElement(irr::KEY_END, new KeyEscap());
                keyMap->addElement(irr::KEY_TAB, new KeyTab());
                return new Keyboard(view, keyMap);
            }
        };
} // graphique

#endif

