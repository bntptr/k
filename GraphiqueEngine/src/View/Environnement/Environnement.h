#ifndef VIEW_ENVIRONNEMENT_H
#define VIEW_ENVIRONNEMENT_H

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

            bool build() {
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

            bool onEvent(const irr::SEvent& event) {
/*
                switch(event.GUIEvent.EventType)
                {
                    case EGET_MENU_ITEM_SELECTED:
                         OnEventGUIMenuItemSelected(event);
                        break;

                    case EGET_FILE_SELECTED:
                         OnEventGUIFileSelected(event);
                        break;

                    case EGET_SCROLL_BAR_CHANGED:
                         OnEventGUIScrollBarChanged(event);
                        break;

                    case EGET_COMBO_BOX_CHANGED:
                         OnEventGUIComboBoxChanged(event);
                        break;

                    case EGET_BUTTON_CLICKED:
                         OnEventGUIButtonClicked(event);
                        break;
                    default:
                        break;
                } //fin du switch(event.GUIEvent.EventType)*/
                return true;
            }
    };
} // graphique

#endif
