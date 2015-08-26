#ifndef IFPSCHARACTER_VIEW_H
#define IFPSCHARACTER_VIEW_H

#include <irrlicht.h>

#include "../../IObjectView.h"
#include "../../../Business/Population/Character/ICharacterEntity.h"

namespace graphique
{
    class IFPSCharacter : public IObjectView
    {
        public:
            IFPSCharacter(){};
            virtual ~IFPSCharacter(){};

            virtual bool draw()=0;
            virtual bool onEvent(EACTIONEVENT event)=0;
            virtual business::ICharacterEntity* getCharacterEntity()=0;
            virtual irr::scene::IAnimatedMeshSceneNode* getNode()=0; // cacher les classes irrlicht
    };
} // graphique

#endif

