#ifndef VIEWCONFIG_H
#define VIEWCONFIG_H

#include <irrlicht.h>

namespace graphique
{
    class ViewConfig
    {
        protected:
            static ViewConfig *_instance;
            irr::u32 windowSizeX;
            irr::u32 windowSizeY;

            irr::video::E_DRIVER_TYPE driverType;

            io::path mediaPath;

        public:
            ViewConfig(){};
            ~ViewConfig(){};

            static ViewConfig* getInstance() {
                if(!ViewConfig::_instance) {
                    ViewConfig::_instance = new ViewConfig();
                }
                return ViewConfig::_instance;
            }

            irr::u32 getWindowSizeX() {
                return this->windowSizeX;
            }

            ViewConfig* setWindowSizeX(irr::u32 x) {
                this->windowSizeX = x;
                return this;
            }

            irr::u32 getWindowSizeY() {
                return this->windowSizeY;
            }

            ViewConfig* setWindowSizeY(irr::u32 y) {
                this->windowSizeY = y;
                return this;
            }

            irr::video::E_DRIVER_TYPE getDriverType() {
                return this->driverType;
            }

            ViewConfig* setDriverType(irr::video::E_DRIVER_TYPE driverType) {
                this->driverType = driverType;
                return this;
            }

            const io::path getMediaPath() {
                return this->mediaPath;
            }

            ViewConfig* setMediaPath(const io::path mediaPath) {
                this->mediaPath = mediaPath;
                return this;
            }

            ViewConfig* load() {
                ViewConfig::getInstance()
                    ->setWindowSizeX(640)
                    ->setWindowSizeX(480)
                    ->setDriverType(irr::video::EDT_OPENGL)
                    ->setMediaPath("../../../media/");
                return this;
            }
    };
    ViewConfig* ViewConfig::_instance = 0;
} // graphique

#endif
