#ifndef VIEW_FPS_CHARACTER_H
#define VIEW_FPS_CHARACTER_H

#include "IFPSCharacter.h"

namespace graphique
{
    class FPSCharacter : public IFPSCharacter
    {
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
                anms = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../../media/gun.md2"),
                                    0, IDFlag_IsPickable | IDFlag_IsHighlightable);
                anms->setPosition(core::vector3df(0,15,0)); // Put its feet on the floor.
                anms->setScale(core::vector3df(1, 1, 1)); // Make it appear realistically scaled
                anms->setMD2Animation(scene::EMAT_RUN); //EMAT_QUOI???  POINT, RUN  voir IAnimatedMeshMD2.h
                /*node->setAnimationSpeed(20.f);*/
                video::SMaterial material;//redéclaration, a donc virer
                material.setTexture(0, driver->getTexture("../../../../media/gun.jpg"));
                material.Lighting = true;
                material.NormalizeNormals = true;
                anms->getMaterial(0) = material;


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
    };
} // graphique

#endif
