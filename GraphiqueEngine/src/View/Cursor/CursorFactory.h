#ifndef CURSOR_FACTORY_H
#define CURSOR_FACTORY_H

#include "CursorEntity.h"

namespace graphique
{
    class CursorFactory
    {
        public:
            static ICursorEntity* createEntity(irr::IrrlichtDevice *device, IView *view) {
                TMap<irr::EMOUSE_INPUT_EVENT, IEmie>* keyMap = new TMap<irr::EMOUSE_INPUT_EVENT, IEmie>();
                IEmie *k = new EmieCount();
                keyMap->addElement(irr::EMIE_COUNT, k);
                keyMap->addElement(irr::EMIE_MOUSE_DOUBLE_CLICK, new EmieDoubleClick());
                keyMap->addElement(irr::EMIE_LMOUSE_LEFT_UP, new EmieLMouseLeftUp());
                keyMap->addElement(irr::EMIE_LMOUSE_PRESSED_DOWN, new EmieLMousePressedDown());
                keyMap->addElement(irr::EMIE_RMOUSE_LEFT_UP, new EmieRMouseLeftUp());
                keyMap->addElement(irr::EMIE_RMOUSE_PRESSED_DOWN, new EmieRMousePressedDown());
                keyMap->addElement(irr::EMIE_MOUSE_MOVED, new EmieMouseMoved());
                keyMap->addElement(irr::EMIE_MOUSE_TRIPLE_CLICK, new EmieMouseTripleClick());
                keyMap->addElement(irr::EMIE_MOUSE_WHEEL, new EmieMouseWheel());
                return new CursorEntity(device, view, keyMap);
            }
    };
} // graphique

#endif



