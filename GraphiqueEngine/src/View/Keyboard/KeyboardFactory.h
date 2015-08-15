#ifndef KEYBOARD_FACTORY_H
#define KEYBOARD_FACTORY_H

#include "Keyboard.h"

namespace graphique
{
    class KeyboardFactory
    {
        public:
            static IKeyboard* createEntity() {
                return new Keyboard();
            }
        };
} // graphique

#endif

