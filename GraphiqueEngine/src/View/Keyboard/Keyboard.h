/**

KEY_LBUTTON
KEY_RBUTTON
KEY_CANCEL
KEY_MBUTTON
KEY_XBUTTON1
KEY_XBUTTON2
KEY_BACK
KEY_TAB
KEY_CLEAR
KEY_RETURN
KEY_SHIFT
KEY_CONTROL
KEY_MENU
KEY_PAUSE
KEY_CAPITAL
KEY_KANA
KEY_HANGUEL
KEY_HANGUL
KEY_JUNJA
KEY_FINAL
KEY_HANJA
KEY_KANJI
KEY_ESCAPE
KEY_CONVERT
KEY_NONCONVERT
KEY_ACCEPT
KEY_MODECHANGE
KEY_SPACE
KEY_PRIOR
KEY_NEXT
KEY_END
KEY_HOME
KEY_LEFT
KEY_UP
KEY_RIGHT
KEY_DOWN
KEY_SELECT
KEY_PRINT
KEY_EXECUT
KEY_SNAPSHOT
KEY_INSERT
KEY_DELETE
KEY_HELP
KEY_KEY_0
KEY_KEY_1
KEY_KEY_2
KEY_KEY_3
KEY_KEY_4
KEY_KEY_5
KEY_KEY_6
KEY_KEY_7
KEY_KEY_8
KEY_KEY_9
KEY_KEY_A
KEY_KEY_B
KEY_KEY_C
KEY_KEY_D
KEY_KEY_E
KEY_KEY_F
KEY_KEY_G
KEY_KEY_H
KEY_KEY_I
KEY_KEY_J
KEY_KEY_K
KEY_KEY_L
KEY_KEY_M
KEY_KEY_N
KEY_KEY_O
KEY_KEY_P
KEY_KEY_Q
KEY_KEY_R
KEY_KEY_S
KEY_KEY_T
KEY_KEY_U
KEY_KEY_V
KEY_KEY_W
KEY_KEY_X
KEY_KEY_Y
KEY_KEY_Z
KEY_LWIN
KEY_RWIN
KEY_APPS
KEY_SLEEP
KEY_NUMPAD0
KEY_NUMPAD1
KEY_NUMPAD2
KEY_NUMPAD3
KEY_NUMPAD4
KEY_NUMPAD5
KEY_NUMPAD6
KEY_NUMPAD7
KEY_NUMPAD8
KEY_NUMPAD9
KEY_MULTIPLY
KEY_ADD
KEY_SEPARATOR
KEY_SUBTRACT
KEY_DECIMAL
KEY_DIVIDE
KEY_F1
KEY_F2
KEY_F3
KEY_F4
KEY_F5
KEY_F6
KEY_F7
KEY_F8
KEY_F9
KEY_F10
KEY_F11
KEY_F12
KEY_F13
KEY_F14
KEY_F15
KEY_F16
KEY_F17
KEY_F18
KEY_F19
KEY_F20
KEY_F21
KEY_F22
KEY_F23
KEY_F24
KEY_NUMLOCK
KEY_SCROLL
KEY_LSHIFT
KEY_RSHIFT
KEY_LCONTROL
KEY_RCONTROL
KEY_LMENU
KEY_RMENU
KEY_PLUS
KEY_COMMA
KEY_MINUS
KEY_PERIOD
KEY_ATTN
KEY_CRSEL
KEY_EXSEL
KEY_EREOF
KEY_PLAY
KEY_ZOOM
KEY_PA1
KEY_OEM_CLEAR
KEY_KEY_CODES_COUNT

*/
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "IKeyboard.h"
#include "Action/IKey.h"

namespace graphique
{
    class Keyboard : public IKeyboard
    {
        protected:
            IKeyboard *thisInstance;
            TMap<irr::EKEY_CODE, IKey>* keyMap;
            IView *view;

        public:
            Keyboard(IView *view, TMap<irr::EKEY_CODE, IKey>* keyMap){
                this->thisInstance = this;
                this->keyMap = keyMap;
                this->view = view;
            };
            ~Keyboard(){};

            IKeyboard* down(irr::EKEY_CODE key) {
                IKey *k = this->keyMap->get(key);

                if (k)
                    k->down();

                return this->thisInstance;
            }

            IKeyboard* up(irr::EKEY_CODE key) {
                IKey *k = this->keyMap->get(key);

                if (k)
                    k->up();

                return this->thisInstance;
            }

            bool isDown(irr::EKEY_CODE key) {
                IKey *k = this->keyMap->get(key);

                if (k)
                    return k->isDown();
                return false;
            }

            IKeyboard* execute(irr::EKEY_CODE key) {
                IKey *k = this->keyMap->get(key);

                if (k)
                    k->execute(this->view);
                return this->thisInstance;
            }

            IKeyboard* executePressed(irr::EKEY_CODE key) {
                IKey *k = this->keyMap->get(key);

                if (k)
                    k->executePressed(this->view);
                return this->thisInstance;
            }

            bool oneEvent(const irr::SEvent& event) {
                this->execute(event.KeyInput.Key);
                return true;
            }

            bool oneEventPressed(const irr::SEvent& event) {
                this->executePressed(event.KeyInput.Key);
                return true;
            }
    };
} // graphique

#endif

