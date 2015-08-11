#ifndef VIEW_CHARACTER_DEPLACEX_H
#define VIEW_CHARACTER_DEPLACEX_H

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
                    ICharacterEntity* entity = character->getCharacterEntity();
                    entity->deplaceX();

                    Vector3d position = entity->getPosition();
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


