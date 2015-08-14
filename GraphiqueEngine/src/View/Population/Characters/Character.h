#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include "ICharacter.h"
#include "Action/DeplaceX.h"

namespace graphique
{
    class Character : public ICharacter
    {
        protected:
            irr::IrrlichtDevice *device;
            business::ICharacterEntity *entity;
            scene::IAnimatedMeshSceneNode* node;

        public:
            Character(irr::IrrlichtDevice *device, business::ICharacterEntity *entity){
                this->device = device;
                this->entity = entity;
            };
            ~Character(){};

            bool draw() {
                using namespace irr;
                std::cout <<"hello ninja !" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = this->device->getVideoDriver();
                scene::ISceneManager* smgr = this->device->getSceneManager();
                gui::IGUIEnvironment* env = this->device->getGUIEnvironment();

                // NINJA
                EMESH code_mesh = this->entity->getMesh();
                scene::IAnimatedMesh *mesh= smgr->getMesh(
                    MEDIA + MESHInfoNames[code_mesh]
                );
                scene::IAnimatedMeshSceneNode* anms =
                    smgr->addAnimatedMeshSceneNode(mesh);

                ETEXTURE code_texture = this->entity->getTexture();
                anms->setMaterialTexture(
                    0,
                    driver->getTexture(MEDIA + TEXTUREInfoNames[code_texture])
                );

                if (anms)
                {
                    anms->setMaterialFlag(video::EMF_LIGHTING, false);

                    anms->setFrameLoop(0, 13);
                    anms->setAnimationSpeed(15);
            		//anms->setMD2Animation(scene::EMAT_RUN);

                    business::Vector3d scale = this->entity->getScale();
                    anms->setScale(core::vector3df(
                        scale.getX(),
                        scale.getY(),
                        scale.getZ()
                    ));

                    business::Vector3d rotation = this->entity->getRotation();
                    anms->setRotation(core::vector3df(
                        rotation.getX(),
                        rotation.getY(),
                        rotation.getZ()
                    ));

                    business::Vector3d position = this->entity->getPosition();
                    anms->setPosition(core::vector3df(
                        position.getX(),
                        position.getY(),
                        position.getZ()
                    ));
                    this->node = anms;
                }
            }

            business::ICharacterEntity* getCharacterEntity() {
                return this->entity;
            }

            scene::IAnimatedMeshSceneNode* getNode() {
                return this->node;
            }

            bool oneEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                character::IAction *action;
                switch(event)
                {
                    case EACTIONEVENT_DEFAULT:
                        break;
                    case EACTIONEVENT_DEPLACE_X:
                        action = new character::DeplaceX();
                        action->execute(this);
                        break;
                    case EACTIONEVENT_DEPLACE_Y:
                        break;
                    case EACTIONEVENT_DEPLACE_Z:
                        break;
                    default:
                    break;
                }
                return true;
            }
    };
} // graphique

#endif
