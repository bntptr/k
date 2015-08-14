#ifndef SKYVIEW_H
#define SKYVIEW_H

#include "ISkyView.h"

namespace graphique
{
    class SkyView : public ISkyView
    {
        protected:
            irr::IrrlichtDevice *device;
            business::ISkyEntity *skyEntity;
            scene::ISceneNode* skybox;
            scene::ISceneNode* skydome;

        public:
            SkyView(irr::IrrlichtDevice *device, business::ISkyEntity *skyEntity){
                this->device = device;
                this->skyEntity = skyEntity;
            };
            ~SkyView(){};


            scene::ISceneNode* getSkyBox(){
                return this->skybox;
            }

            scene::ISceneNode* getSkyDome(){
                return this->skydome;
            }

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // create skybox and skydome
                driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

                this->skybox=smgr->addSkyBoxSceneNode(
                    driver->getTexture(MEDIA + "irrlicht2_up.jpg"),
                    driver->getTexture(MEDIA + "irrlicht2_dn.jpg"),
                    driver->getTexture(MEDIA + "irrlicht2_lf.jpg"),
                    driver->getTexture(MEDIA + "irrlicht2_rt.jpg"),
                    driver->getTexture(MEDIA + "irrlicht2_ft.jpg"),
                    driver->getTexture(MEDIA + "irrlicht2_bk.jpg"));
                this->skydome=smgr->addSkyDomeSceneNode(driver->getTexture(MEDIA + "skydome.jpg"),16,8,0.95f,2.0f);

                driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
            }
    };
} // graphique

#endif
