#ifndef VIEW_CUBE_SCENE_NODE_H
#define VIEW_CUBE_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class CubeSceneNode : public SceneNode
    {
        public:
            CubeSceneNode(irr::IrrlichtDevice *device) : SceneNode(device) {
                this->device = device;
            };
            ~CubeSceneNode(){};

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
