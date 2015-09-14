#ifndef VIEW_SKY_SCENE_NODE_H
#define VIEW_SKY_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    /**
     * Utilité de cette classe?
     */
    class SkySceneNode : public SceneNode
    {
        protected:
            irr::scene::ISceneNode *skybox;
            irr::scene::ISceneNode *skydome;

            ETEXTURE textureSkyDome;
            ETEXTURE textureSkyBoxUp;
            ETEXTURE textureSkyBoxDn;
            ETEXTURE textureSkyBoxLf;
            ETEXTURE textureSkyBoxRt;
            ETEXTURE textureSkyBoxFt;
            ETEXTURE textureSkyBoxBk;

        public:
            SkySceneNode(
                irr::IrrlichtDevice *device,
                ETEXTURE textureSkyDome,
                ETEXTURE textureSkyBoxUp,
                ETEXTURE textureSkyBoxDn,
                ETEXTURE textureSkyBoxLf,
                ETEXTURE textureSkyBoxRt,
                ETEXTURE textureSkyBoxFt,
                ETEXTURE textureSkyBoxBk
            ) : SceneNode() {
                this->device = device;
                this->textureSkyDome = textureSkyDome;
                this->textureSkyBoxUp = textureSkyBoxUp;
                this->textureSkyBoxDn = textureSkyBoxDn;
                this->textureSkyBoxLf = textureSkyBoxLf;
                this->textureSkyBoxRt = textureSkyBoxRt;
                this->textureSkyBoxFt = textureSkyBoxFt;
                this->textureSkyBoxBk = textureSkyBoxBk;
            };
            ~SkySceneNode(){};

            bool build(ICameraService* camera) {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // create skybox and skydome
                driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

                this->skybox = smgr->addSkyBoxSceneNode(
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxUp]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxDn]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxLf]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxRt]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxFt]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxBk]));
                this->skydome = smgr->addSkyDomeSceneNode(
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyDome]),16,8,0.95f,2.0f
                );

                driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);

                this->skybox->setVisible(true);
                this->skydome->setVisible(false);

                return true;
            }

            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                return true;
            }

            bool onEvent(const irr::SEvent& event) {
                return true;
            }
    };
} // graphique

#endif
