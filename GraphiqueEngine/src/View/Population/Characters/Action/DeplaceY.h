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
                    ISceneNode* node = character->getNode();
                    node->setPosition(position);
                }
        };
    }
} // graphique

#endif



