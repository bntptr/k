#ifndef VIEW_CHARACTER_SCENE_NODE_H
#define VIEW_CHARACTER_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class CharacterSceneNode : public SceneNode
    {
        protected:
            irr::scene::IAnimatedMeshSceneNode* node;

        public:
            CharacterSceneNode(
                irr::IrrlichtDevice *device,
                int id,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) : SceneNode(
                device,
                id,
                position,
                rotation,
                scale,
                texture,
                mesh
            ) {};
            ~CharacterSceneNode(){};

            bool build(ICameraService* camera) {
                using namespace irr;
                std::cout <<"hello ninja !" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = this->device->getVideoDriver();
                scene::ISceneManager* smgr = this->device->getSceneManager();
                gui::IGUIEnvironment* env = this->device->getGUIEnvironment();

                // NINJA
                EMESH code_mesh = this->getMesh();
                scene::IAnimatedMesh *mesh= smgr->getMesh(
                    MEDIA + MESHInfoNames[code_mesh]
                );
                scene::IAnimatedMeshSceneNode* anms =
                    smgr->addAnimatedMeshSceneNode(
                        mesh,
                        0,
                        this->getId()
                );

// Pour la selection avec le curseur
                scene::ITriangleSelector* selector = 0;
                selector = smgr->createTriangleSelector(anms);
                anms->setTriangleSelector(selector);
                selector->drop();
// fin selection curseur
                ETEXTURE code_texture = this->getTexture();

                if ("" != TEXTUREInfoNames[code_texture]) {
                    anms->setMaterialTexture(
                        0,
                        driver->getTexture(MEDIA + TEXTUREInfoNames[code_texture])
                    );
                }

                if (anms)
                {
                    anms->setMaterialFlag(video::EMF_LIGHTING, false);

                    anms->setFrameLoop(0, 13);
                    anms->setAnimationSpeed(15);
            		//anms->setMD2Animation(scene::EMAT_RUN);

                    business::Vector3d scale = this->getScale();
                    anms->setScale(core::vector3df(
                        scale.getX(),
                        scale.getY(),
                        scale.getZ()
                    ));

                    business::Vector3d rotation = this->getRotation();
                    anms->setRotation(core::vector3df(
                        rotation.getX(),
                        rotation.getY(),
                        rotation.getZ()
                    ));

                    business::Vector3d position = this->getPosition();
                    anms->setPosition(core::vector3df(
                        position.getX(),
                        position.getY(),
                        position.getZ()
                    ));
                    this->node = anms;
                }
                return true;
            }

            /**
             * A déplacer dans View2d
             */
            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                using namespace irr;
                //std::cout <<"hello ninja !" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = this->device->getVideoDriver();

                u32 time = this->device->getTimer()->getTime();
                core::rect<s32> imp1(349,15,385,78);
                core::rect<s32> imp2(387,15,423,78);
                ETEXTURE code_texture = this->getTexture();
                business::Vector3d position = this->getPosition();

                /// Couleur transparente
                video::ITexture *image = driver->getTexture(MEDIA + TEXTURE2DInfoNames[code_texture]);
                driver->makeColorKeyTexture(image, core::position2d<s32>(0,0));
                // draw flying imp
                driver->draw2DImage(
                    image,
                    core::position2d<s32>(position.getX()-18,position.getZ()-31),
                    (time/500 % 2) ? imp1 : imp2,
                    0,
                    video::SColor(255,255,255,255),
                    true
                );
                return true;
            }

            bool onEvent(const irr::SEvent& event) {

                return true;
            }

            ISceneNode* setPosition(business::Vector3d position) {
                this->position = position;
                this->node->setPosition(irr::core::vector3df(
                    position.getX(),
                    position.getY(),
                    position.getZ()
                ));
                return this->thisInstance;
            }

            business::Vector3d getRotation(){
                return this->rotation;
            }

            ISceneNode* setRotation(business::Vector3d rotation){
                this->rotation = rotation;
                this->node->setRotation(irr::core::vector3df(
                    rotation.getX(),
                    rotation.getY(),
                    rotation.getZ()
                ));
                return this->thisInstance;
            }

            business::Vector3d getScale(){
                return this->scale;
            }

            ISceneNode* setScale(business::Vector3d scale){
                this->scale = scale;
                this->node->setScale(irr::core::vector3df(
                    scale.getX(),
                    scale.getY(),
                    scale.getZ()
                ));
                return this->thisInstance;
            }
    };
} // graphique

#endif
