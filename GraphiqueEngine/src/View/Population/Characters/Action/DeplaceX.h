#ifndef VIEW_CHARACTER_DEPLACE_X_H
#define VIEW_CHARACTER_DEPLACE_X_H

#include "IAction.h"

namespace graphique
{
    namespace character
    {
        class DeplaceX : public IAction
        {
            public:
                DeplaceX(){};
                virtual ~DeplaceX(){};

                int execute(ICharacter *character) {
                    business::ICharacterEntity* entity = character->getCharacterEntity();
                    entity->onEvent(EACTIONEVENT_DEPLACE_X);

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


