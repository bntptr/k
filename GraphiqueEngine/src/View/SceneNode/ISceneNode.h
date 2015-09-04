#ifndef VIEW_ISCENE_NODE_H
#define VIEW_ISCENE_NODE_H

#include <irrlicht.h>

namespace graphique
{
    class ISceneNode
    {
        public:
            ISceneNode(){};
            virtual ~ISceneNode(){};

            virtual void setDevice(irr::IrrlichtDevice *device)=0;

            virtual bool build()=0;
            virtual bool draw()=0;
            virtual bool onEvent(const irr::SEvent& event)=0;

            virtual int getId()=0;
            virtual EMESH getMesh()=0;
            virtual ISceneNode* setMesh(EMESH mesh)=0;
            virtual ETEXTURE getTexture()=0;
            virtual ISceneNode* setTexture(ETEXTURE texture)=0;
            virtual business::Vector3d getPosition()=0;
            virtual ISceneNode* setPosition(business::Vector3d position)=0;
            virtual business::Vector3d getRotation()=0;
            virtual ISceneNode* setRotation(business::Vector3d rotation)=0;
            virtual business::Vector3d getScale()=0;
            virtual ISceneNode* setScale(business::Vector3d scale)=0;
    };
} // graphique

#endif
