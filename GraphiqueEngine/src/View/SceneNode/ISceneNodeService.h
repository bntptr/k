#ifndef VIEW_ISCENE_NODE_SERVICE_H
#define VIEW_ISCENE_NODE_SERVICE_H

#include "ISceneNode.h"

namespace graphique
{
    class ISceneNodeService
    {
        public:
            ISceneNodeService(){};
            virtual ~ISceneNodeService(){};

            virtual bool build()=0;
            virtual bool draw()=0;
            virtual bool onEvent(const irr::SEvent& event)=0;

            virtual ISceneNodeService* setCameraService(ICameraService* camera)=0;

            virtual ISceneNode* addCubeSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture
            )=0;
            virtual ISceneNode* addSphereSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture
            )=0;
            virtual ISceneNode* addOctTreeSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale
            )=0;
            virtual ISceneNode* addCharacterSceneNode(
                int id,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            )=0;
            virtual ISceneNode* addTerrainSceneNode(
                int id,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            )=0;
            virtual ISceneNode* addSkyBoxSceneNode(
                ETEXTURE textureSkyBoxUp,
                ETEXTURE textureSkyBoxDn,
                ETEXTURE textureSkyBoxLf,
                ETEXTURE textureSkyBoxRt,
                ETEXTURE textureSkyBoxFt,
                ETEXTURE textureSkyBoxBk
            )=0;
            virtual ISceneNode* addSkyDomeSceneNode(
                ETEXTURE textureSkyDome
            )=0;
    };
}

#endif




