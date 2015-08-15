#ifndef SKYVIEW_H
#define SKYVIEW_H

#include "ISkyView.h"
#include "Action/IAction.h"
#include "Action/ChangeSky.h"

namespace graphique
{
    class SkyView : public ISkyView
    {
        protected:
            irr::IrrlichtDevice *device;
            business::ISkyEntity *skyEntity;
            scene::ISceneNode* skybox;
            scene::ISceneNode* skydome;
            bool showBox;

        public:
            SkyView(irr::IrrlichtDevice *device, business::ISkyEntity *skyEntity){
                this->device = device;
                this->skyEntity = skyEntity;
                this->showBox = true;
            };
            ~SkyView(){};


            scene::ISceneNode* getSkyBox(){
                return this->skybox;
            }

            scene::ISceneNode* getSkyDome(){
                return this->skydome;
            }

            bool getShowBox(){
                return this->showBox;
            }

            bool setShowBox(bool showBox){
                return this->showBox = showBox;
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

                this->skybox->setVisible(true);
                this->skydome->setVisible(false);
            }

            bool oneEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                sky::IAction *action;
                switch(event)
                {
                    case EACTIONEVENT_CHANGE_SKY:
                        action = new sky::ChangeSky();
                        action->execute(this);
                        break;
                    default:
                    break;
                }
                return true;
            }
    };
} // graphique

#endif
