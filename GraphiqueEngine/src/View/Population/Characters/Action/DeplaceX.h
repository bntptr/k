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
                    ISceneNode* node = character->getNode();
                    node->setPosition(position);
                }
        };
    }
} // graphique

#endif


