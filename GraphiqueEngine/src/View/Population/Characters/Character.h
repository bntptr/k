/**
Source :
http://irrlicht.sourceforge.net/docu/_i_animated_mesh_m_d2_8h_source.html
00016     enum EMD2_ANIMATION_TYPE
00017     {
00018         EMAT_STAND = 0,
00019         EMAT_RUN,
00020         EMAT_ATTACK,
00021         EMAT_PAIN_A,
00022         EMAT_PAIN_B,
00023         EMAT_PAIN_C,
00024         EMAT_JUMP,
00025         EMAT_FLIP,
00026         EMAT_SALUTE,
00027         EMAT_FALLBACK,
00028         EMAT_WAVE,
00029         EMAT_POINT,
00030         EMAT_CROUCH_STAND,
00031         EMAT_CROUCH_WALK,
00032         EMAT_CROUCH_ATTACK,
00033         EMAT_CROUCH_PAIN,
00034         EMAT_CROUCH_DEATH,
00035         EMAT_DEATH_FALLBACK,
00036         EMAT_DEATH_FALLFORWARD,
00037         EMAT_DEATH_FALLBACKSLOW,
00038         EMAT_BOOM,
00039
00041         EMAT_COUNT
00042     };
*/

#ifndef VIEW_CHARACTER_VIEW_H
#define VIEW_CHARACTER_VIEW_H

#include "../../SceneNode/ISceneNodeService.h"
#include "ICharacter.h"
#include "Action/Actions.h"
#include "../../ViewConfig.h"

namespace graphique
{
    class Character : public ICharacter
    {
        protected:
            ISceneNodeService *sceneNodeService;
            ISceneNode *node;
            irr::IrrlichtDevice *device;
            business::ICharacterEntity *entity;

            TMap<EACTIONEVENT, character::IAction>* keyMap;

        public:
            Character(
                ISceneNodeService *service,
                business::ICharacterEntity *entity,
                TMap<EACTIONEVENT, character::IAction>* keyMap
            ){
                this->sceneNodeService = service;
                this->entity = entity;
                this->keyMap = keyMap;
            };
            ~Character(){};

            bool build() {
                this->node = this->sceneNodeService->addCharacterSceneNode(
                    this->getId(),
                    this->entity->getPosition(),
                    this->entity->getRotation(),
                    this->entity->getScale(),
                    this->entity->getTexture(),
                    this->entity->getMesh()
                );
                return true;
            }

            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {

                return true;
            }

            business::ICharacterEntity* getCharacterEntity() {
                return this->entity;
            }

            ISceneNode* getNode() {
                return this->node;
            }

            bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                character::IAction *action  = this->keyMap->get(event);

                if (action) {
                    action->execute(this);
                }

                return true;
            }
    };
} // graphique

#endif
