/**
numerator:
EMIE_LMOUSE_PRESSED_DOWN 	Left mouse button was pressed down.
EMIE_RMOUSE_PRESSED_DOWN 	Right mouse button was pressed down.
EMIE_MMOUSE_PRESSED_DOWN 	Middle mouse button was pressed down.
EMIE_LMOUSE_LEFT_UP 	Left mouse button was left up.
EMIE_RMOUSE_LEFT_UP 	Right mouse button was left up.
EMIE_MMOUSE_LEFT_UP 	Middle mouse button was left up.
EMIE_MOUSE_MOVED 	The mouse cursor changed its position.
EMIE_MOUSE_WHEEL 	The mouse wheel was moved. Use Wheel value in event data to find out in what direction and how fast.
EMIE_MOUSE_DOUBLE_CLICK 	Mouse double click. This event is generated after the second EMIE_LMOUSE_PRESSED_DOWN event.
EMIE_MOUSE_TRIPLE_CLICK 	Mouse triple click. This event is generated after the third EMIE_LMOUSE_PRESSED_DOWN event.
EMIE_COUNT 	No real event. Just for convenience to get number of events.
*/
#include "EmieCount.h"
#include "EmieDoubleClick.h"
#include "EmieLMouseLeftUp.h"
#include "EmieLMousePressedDown.h"
#include "EmieRMouseLeftUp.h"
#include "EmieRMousePressedDown.h"
#include "EmieMouseMoved.h"
#include "EmieMouseTripleClick.h"
#include "EmieMouseWheel.h"
