#ifndef VIEW_CHARACTER_SCENE_NODE_H
#define VIEW_CHARACTER_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class CharacterSceneNode : public SceneNode
    {
        public:
            CharacterSceneNode(irr::IrrlichtDevice *device) : SceneNode(device) {
                this->device = device;
            };
            ~CharacterSceneNode(){};

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
