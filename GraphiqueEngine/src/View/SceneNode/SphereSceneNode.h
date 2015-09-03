#ifndef VIEW_SPHERE_SCENE_NODE_H
#define VIEW_SPHERE_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class SphereSceneNode : public SceneNode
    {
        public:
            SphereSceneNode(irr::IrrlichtDevice *device) : SceneNode(device) {
                this->device = device;
            };
            ~SphereSceneNode(){};

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
