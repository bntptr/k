#ifndef VIEW_TERRAIN_SCENE_NODE_H
#define VIEW_TERRAIN_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class TerrainSceneNode : public SceneNode
    {
        public:
            TerrainSceneNode(irr::IrrlichtDevice *device) : SceneNode() {
                this->device = device;
                this->build();
            };
            ~TerrainSceneNode(){};

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
