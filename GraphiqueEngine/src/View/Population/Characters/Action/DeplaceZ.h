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
                    entity->onEvent(EACTIONEVENT_DEPLACE_Z);

                    business::Vector3d position = entity->getPosition();
                    ISceneNode* node = character->getNode();
                    node->setPosition(position);
                }
        };
    }
} // graphique

#endif




