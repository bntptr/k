#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include "IEnvironnement.h"

namespace graphique
{
    class Environnement : public IEnvironnement
    {
        protected:
            irr::IrrlichtDevice *device;
        public:
            Environnement(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~Environnement(){};

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add irrlicht logo
                env->addImage(driver->getTexture(
                    MEDIA +
                    "irrlichtlogo2.png"),
                    core::position2d<s32>(10,10));

                //set other font
                env->getSkin()->setFont(env->getFont(MEDIA + "fontlucida.png"));

                // add some help text
                env->addStaticText(
                    L"Press 'Q' or 'P' to change wireframe mode\nPress 'D' to toggle detail map\nPress 'S' to toggle skybox/skydome\n 'W', 'X', 'C' and 'V' jostick",
                    core::rect<s32>(10,421,250,475), true, true, 0, -1, true);
            }
    };
} // graphique

#endif
