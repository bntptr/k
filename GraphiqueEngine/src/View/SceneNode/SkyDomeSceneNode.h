#ifndef VIEW_SKY_DOME_SCENE_NODE_H
#define VIEW_SKY_DOME_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class SkyDomeSceneNode : public SceneNode
    {
        protected:
            ETEXTURE textureSkyDome;

        public:
            SkyDomeSceneNode(
                irr::IrrlichtDevice *device,
                ETEXTURE textureSkyDome
            ) : SceneNode() {
                this->device = device;
                this->textureSkyDome = textureSkyDome;
            };
            ~SkyDomeSceneNode(){};

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

                this->node = smgr->addSkyDomeSceneNode(
                    driver->getTexture(MEDIA + TEXTUREInfoNames[this->textureSkyDome]),16,8,0.95f,2.0f
                );

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

