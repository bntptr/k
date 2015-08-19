#ifndef IKEYBOARD_H
#define IKEYBOARD_H

#include <irrlicht.h>

namespace graphique
{
    class IKeyboard
    {
        public:
            IKeyboard(){};
            virtual ~IKeyboard(){};

            virtual IKeyboard* down(irr::EKEY_CODE key)=0;
            virtual IKeyboard* up(irr::EKEY_CODE key)=0;
            virtual bool isDown(irr::EKEY_CODE key)=0;
            virtual IKeyboard* execute(irr::EKEY_CODE key)=0;
            virtual IKeyboard* executePressed(irr::EKEY_CODE key)=0;

            virtual bool oneEvent(const irr::SEvent& event)=0;
            virtual bool oneEventPressed(const irr::SEvent& event)=0;
    };
} // graphique

#endif

