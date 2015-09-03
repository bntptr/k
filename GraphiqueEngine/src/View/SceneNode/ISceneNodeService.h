#ifndef VIEW_ISCENE_NODE_SERVICE_H
#define VIEW_ISCENE_NODE_SERVICE_H

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

            virtual ISceneNodeService* addCubeSceneNode()=0;
            virtual ISceneNodeService* addSphereSceneNode()=0;
            virtual ISceneNodeService* addOctTreeSceneNode(
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale
            )=0;
            virtual ISceneNodeService* addCharacterSceneNode()=0;
            virtual ISceneNodeService* addTerrainSceneNode()=0;
            virtual ISceneNodeService* addSkySceneNode()=0;
    };
}

#endif




