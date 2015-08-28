#ifndef VIEW_KEYBOARD_2D_H
#define VIEW_KEYBOARD_2D_H

#include "../Keyboard.h"

namespace graphique
{
    class Keyboard2d : public Keyboard
    {
        protected:
            IKeyboard *thisInstance;
            TMap<irr::EKEY_CODE, IKey>* keyMap;
            IView *view;

        public:
            Keyboard2d(IView *view, TMap<irr::EKEY_CODE, IKey>* keyMap) : Keyboard(view, keyMap){
            };
            ~Keyboard2d(){};
    };
} // graphique

#endif

