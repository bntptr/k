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

            virtual bool build()=0;
            virtual bool draw()=0;
            virtual bool onEvent(const irr::SEvent& event)=0;
    };
} // graphique

#endif
