#ifndef VIEW_SCENE_NODE_H
#define VIEW_SCENE_NODE_H

#include "ISceneNode.h"

namespace graphique
{
    class SceneNode : public ISceneNode
    {
        protected:
            irr::IrrlichtDevice *device;
        public:
            SceneNode(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~SceneNode(){};

            bool build() {

                return true;
            }

            bool draw() {

                return true;
            }

            bool onEvent(const irr::SEvent& event) {

                return true;
            }
    };
} // graphique

#endif
