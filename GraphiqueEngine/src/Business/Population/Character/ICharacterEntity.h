#ifndef ICHARACTERENTITY_H
#define ICHARACTERENTITY_H

#include "../../../View/EventReceiver/Action/EActionEvent.h"
#include "../../../Media/Texture/ETexture.h"
#include "../../../Media/Mesh/EMesh.h"
#include "Vector3d/Vector3d.h"

namespace business
{
    class ICharacterEntity
    {
        public:
            ICharacterEntity(){};
            virtual ~ICharacterEntity(){};

            virtual bool oneEvent(EACTIONEVENT event)=0;

            virtual EMESH getMesh()=0;
            virtual ICharacterEntity* setMesh(EMESH mesh)=0;
            virtual ETEXTURE getTexture()=0;
            virtual ICharacterEntity* setTexture(ETEXTURE texture)=0;
            virtual Vector3d getPosition()=0;
            virtual ICharacterEntity* setPosition(Vector3d position)=0;
            virtual Vector3d getRotation()=0;
            virtual ICharacterEntity* setRotation(Vector3d rotation)=0;
            virtual Vector3d getScale()=0;
            virtual ICharacterEntity* setScale(Vector3d scale)=0;
    };
} // business

#endif
