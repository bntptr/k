#ifndef VIEW_CHARACTER_DEPLACE_Z_H
#define VIEW_CHARACTER_DEPLACE_Z_H

#include "IAction.h"

namespace graphique
{
    namespace character
    {
        class DeplaceZ : public IAction
        {
            public:
                DeplaceZ(){};
                virtual ~DeplaceZ(){};

                int execute(ICharacter *character) {
                    business::ICharacterEntity* entity = character->getCharacterEntity();
                    entity->oneEvent(EACTIONEVENT_DEPLACE_Z);

                    business::Vector3d position = entity->getPosition();
                    scene::IAnimatedMeshSceneNode* node = character->getNode();
                    node->setPosition(core::vector3df(
                        position.getX(),
                        position.getY(),
                        position.getZ()
                    ));
                }
        };
    }
} // graphique

#endif




