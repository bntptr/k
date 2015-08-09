#ifndef ICHARACTERVIEW_H
#define ICHARACTERVIEW_H

#include <irrlicht.h>

#include "../../IObjectView.h"
#include "../../../Business/Character/ICharacterEntity.h"

namespace graphique
{
    class ICharacter : public IObjectView
    {
    public:
        ICharacter(){};
        virtual ~ICharacter(){};

        virtual bool draw()=0;
    };
} // graphique

#endif

