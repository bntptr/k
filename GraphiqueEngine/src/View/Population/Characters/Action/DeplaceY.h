#ifndef VIEW_CHARACTER_DEPLACE_Y_H
#define VIEW_CHARACTER_DEPLACE_Y_H

#include "IAction.h"

namespace graphique
{
    namespace character
    {
        class DeplaceY : public IAction
        {
            public:
                DeplaceY(){};
                virtual ~DeplaceY(){};

                int execute(ICharacter *character) {
                    business::ICharacterEntity* entity = character->getCharacterEntity();
                    entity->onEvent(EACTIONEVENT_DEPLACE_Y);

                    business::Vector3d position = entity->getPosition();
                    irr::scene::IAnimatedMeshSceneNode* node = character->getNode();
                    node->setPosition(irr::core::vector3df(
                        position.getX(),
                        position.getY(),
                        position.getZ()
                    ));
                }
        };
    }
} // graphique

#endif



