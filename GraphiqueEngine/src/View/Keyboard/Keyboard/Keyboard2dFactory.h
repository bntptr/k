#ifndef VIEW_KEYBOARD_2D_FACTORY_H
#define VIEW_KEYBOARD_2D_FACTORY_H

#include <irrlicht.h>
#include "Keyboard2d.h"

namespace graphique
{
    class Keyboard2dFactory
    {
        public:
            static IKeyboard* createEntity(IView *view) {
                TMap<irr::EKEY_CODE, IKey>* keyMap = new TMap<irr::EKEY_CODE, IKey>();
                keyMap->addElement(irr::KEY_KEY_W, new KeyW());
                keyMap->addElement(irr::KEY_KEY_X, new KeyX());
                keyMap->addElement(irr::KEY_KEY_C, new KeyC());
                keyMap->addElement(irr::KEY_KEY_V, new KeyV());
                keyMap->addElement(irr::KEY_KEY_P, new KeyP());
                keyMap->addElement(irr::KEY_END, new KeyEscap());
                keyMap->addElement(irr::KEY_TAB, new KeyTab());
                return new Keyboard2d(view, keyMap);
            }
        };
} // graphique

#endif

