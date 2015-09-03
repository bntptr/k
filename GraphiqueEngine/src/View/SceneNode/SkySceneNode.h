#ifndef VIEW_SKY_SCENE_NODE_H
#define VIEW_SKY_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class SkySceneNode : public SceneNode
    {
        public:
            SkySceneNode(irr::IrrlichtDevice *device) : SceneNode(device) {
                this->device = device;
            };
            ~SkySceneNode(){};

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
