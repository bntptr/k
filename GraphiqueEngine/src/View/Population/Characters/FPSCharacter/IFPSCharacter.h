#ifndef VIEW_IFPS_CHARACTER_H
#define VIEW_IFPS_CHARACTER_H

#include <irrlicht.h>

#include "../Character.h"

namespace graphique
{
    class IFPSCharacter : public Character
    {
        public:
            IFPSCharacter(){};
            virtual ~IFPSCharacter(){};
    };
} // graphique

#endif

