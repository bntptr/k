#ifndef FPSCHARACTER_VIEW_H
#define FPSCHARACTER_VIEW_H

#include "IFPSCharacter.h"
/#include "Action/DeplaceX.h"

namespace graphique
{
    class FPSCharacter : public IFPSCharacter
    {
        protected:
            irr::IrrlichtDevice *device;
            business::ICharacterEntity *entity;
            scene::IAnimatedMeshSceneNode* node;

        public:
            FPSCharacter(irr::IrrlichtDevice *device, business::ICharacterEntity *entity){
                this->device = device;
                this->entity = entity;
            };
            ~FPSCharacter(){};

            bool draw() {
                using namespace irr;
                std::cout <<"hello FPSCharacter !" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = this->device->getVideoDriver();
                scene::ISceneManager* smgr = this->device->getSceneManager();
                gui::IGUIEnvironment* env = this->device->getGUIEnvironment();

    //==========================================================================
	//                           Gun
	// Add an MD2 node, which uses vertex-based animation.
	anms = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/gun.md2"),
						0, IDFlag_IsPickable | IDFlag_IsHighlightable);
	anms->setPosition(core::vector3df(0,15,0)); // Put its feet on the floor.
	anms->setScale(core::vector3df(1, 1, 1)); // Make it appear realistically scaled
    anms->setMD2Animation(scene::EMAT_RUN); //EMAT_QUOI???  POINT, RUN  voir IAnimatedMeshMD2.h
	/*node->setAnimationSpeed(20.f);*/
	//video::SMaterial material;//redéclaration, a donc virer
	material.setTexture(0, driver->getTexture("../../../media/gun.jpg"));
	material.Lighting = true;
	material.NormalizeNormals = true;
	anms->getMaterial(0) = material;

	// Now create a triangle selector for it.  The selector will know that it
	// is associated with an animated node, and will update itself as necessary.
	selector = smgr->createTriangleSelector(anms);
	anms->setTriangleSelector(selector);
	selector->drop(); // We're done with this selector, so drop it now.
                // NINJA
                /*EMESH code_mesh = this->entity->getMesh();
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
            		//anms->setMD2Animation(scene::EMAT_RUN);*/

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

            bool onEvent(EACTIONEVENT event) {
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
