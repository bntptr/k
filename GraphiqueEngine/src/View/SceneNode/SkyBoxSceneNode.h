#ifndef VIEW_SKY_BOX_SCENE_NODE_H
#define VIEW_SKY_BOX_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class SkyBoxSceneNode : public SceneNode
    {
        protected:
            ETEXTURE textureSkyBoxUp;
            ETEXTURE textureSkyBoxDn;
            ETEXTURE textureSkyBoxLf;
            ETEXTURE textureSkyBoxRt;
            ETEXTURE textureSkyBoxFt;
            ETEXTURE textureSkyBoxBk;

        public:
            SkyBoxSceneNode(
                irr::IrrlichtDevice *device,
                ETEXTURE textureSkyBoxUp,
                ETEXTURE textureSkyBoxDn,
                ETEXTURE textureSkyBoxLf,
                ETEXTURE textureSkyBoxRt,
                ETEXTURE textureSkyBoxFt,
                ETEXTURE textureSkyBoxBk
            ) : SceneNode() {
                this->device = device;
                this->textureSkyBoxUp = textureSkyBoxUp;
                this->textureSkyBoxDn = textureSkyBoxDn;
                this->textureSkyBoxLf = textureSkyBoxLf;
                this->textureSkyBoxRt = textureSkyBoxRt;
                this->textureSkyBoxFt = textureSkyBoxFt;
                this->textureSkyBoxBk = textureSkyBoxBk;
            };
            ~SkyBoxSceneNode(){};

            bool build() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // create skybox and skydome
                driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

                this->node = smgr->addSkyBoxSceneNode(
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxUp]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxDn]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxLf]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxRt]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxFt]),
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyBoxBk]));

                driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);

                return true;
            }

            bool draw() {

                return true;
            }

            bool onEvent(const irr::SEvent& event) {

                return true;
            }
    };
} // graphique

#endif

