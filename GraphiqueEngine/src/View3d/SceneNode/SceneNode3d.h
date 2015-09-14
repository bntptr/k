#ifndef VIEW_SCENE_NODE_3D_H
#define VIEW_SCENE_NODE_3D_H

#include "ISceneNode3d.h"

namespace graphique
{
    class SceneNode3d : public SceneNode
    {
        public:
            SceneNode3d(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~SceneNode3d(){};

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
