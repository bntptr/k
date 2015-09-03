#ifndef ICHARACTERVIEW_H
#define ICHARACTERVIEW_H

#include <irrlicht.h>

#include "../../IObjectView.h"
#include "../../../Business/Population/Character/ICharacterEntity.h"
#include "../../SceneNode/ISceneNode.h"

namespace graphique
{
    class ICharacter : public IObjectView
    {
        public:
            ICharacter(){};
            virtual ~ICharacter(){};

            virtual bool build()=0;
            virtual bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale)=0;
            virtual bool onEvent(EACTIONEVENT event)=0;
            virtual business::ICharacterEntity* getCharacterEntity()=0;
            virtual ISceneNode* getNode()=0;
    };
} // graphique

#endif

