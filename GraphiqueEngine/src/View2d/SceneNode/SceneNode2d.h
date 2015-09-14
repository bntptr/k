#ifndef VIEW_SCENE_NODE_2D_H
#define VIEW_SCENE_NODE_2D_H

#include "SceneNode.h"

namespace graphique
{
    class SceneNode2d : public SceneNode
    {
        public:
            SceneNode2d(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~SceneNode2d(){};

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
