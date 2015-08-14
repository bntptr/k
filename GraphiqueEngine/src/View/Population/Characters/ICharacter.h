#ifndef ICHARACTERVIEW_H
#define ICHARACTERVIEW_H

#include <irrlicht.h>

#include "../../IObjectView.h"
#include "../../../Business/Population/Character/ICharacterEntity.h"

namespace graphique
{
    class ICharacter : public IObjectView
    {
    public:
        ICharacter(){};
        virtual ~ICharacter(){};

        virtual bool draw()=0;
        virtual bool oneEvent(EACTIONEVENT event)=0;
        virtual business::ICharacterEntity* getCharacterEntity()=0;
        virtual scene::IAnimatedMeshSceneNode* getNode()=0; // cacher les classes irrlicht
    };
} // graphique

#endif

