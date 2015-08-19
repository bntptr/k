#ifndef IGROUNDENTITY_H
#define IGROUNDENTITY_H

#include "../../Kutility/kutility.h"
#include "../../Business/Event/EActionEvent.h"
#include "../../Media/Texture/ETexture.h"
#include "../../Media/Mesh/EMesh.h"

namespace business
{
    class IGroundEntity
    {
        public:
            IGroundEntity(){};
            virtual ~IGroundEntity(){};

            virtual bool oneEvent(EACTIONEVENT event)=0;

            virtual EMESH getMesh()=0;
            virtual IGroundEntity* setMesh(EMESH mesh)=0;
            virtual ETEXTURE getTexture()=0;
            virtual IGroundEntity* setTexture(ETEXTURE texture)=0;
            virtual Vector3d getPosition()=0;
            virtual IGroundEntity* setPosition(Vector3d position)=0;
            virtual Vector3d getRotation()=0;
            virtual IGroundEntity* setRotation(Vector3d rotation)=0;
            virtual Vector3d getScale()=0;
            virtual IGroundEntity* setScale(Vector3d scale)=0;
    };
} // business

#endif
