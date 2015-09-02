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
    };
}

#endif




