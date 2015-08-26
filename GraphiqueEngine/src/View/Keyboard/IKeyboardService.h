#ifndef VIEW_IKEYBOARD_SERVICE_H
#define VIEW_IKEYBOARD_SERVICE_H

#include "Action/IKey.h"
#include "IKeyboard.h"

namespace graphique
{
    class IKeyboardService
    {
        public:
            IKeyboardService(){};
            virtual ~IKeyboardService(){};

            virtual IKeyboard* down(irr::EKEY_CODE key)=0;
            virtual IKeyboard* up(irr::EKEY_CODE key)=0;
            virtual bool isDown(irr::EKEY_CODE key)=0;
            virtual IKeyboard* execute(irr::EKEY_CODE key)=0;
            virtual IKeyboard* executePressed(irr::EKEY_CODE key)=0;

            virtual bool onEvent(const irr::SEvent& event)=0;
            virtual bool onEventPressed(const irr::SEvent& event)=0;
    };
}

#endif




