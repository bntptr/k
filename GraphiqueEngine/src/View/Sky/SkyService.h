#ifndef VIEW_SKY_SERVICE_H
#define VIEW_SKY_SERVICE_H

#include "SkyViewFactory.h"
#include "ISkyService.h"

namespace graphique
{
    class SkyService : public ISkyService
    {
        protected:
            ISkyService* thisInstance;
            ISkyView *sky;

        public:
            SkyService(irr::IrrlichtDevice *device, business::ISkyEntity *skyEntity){
                this->thisInstance = this;
                this->sky = SkyViewFactory::createEntity(device, skyEntity);
            };
            ~SkyService(){};

            scene::ISceneNode* getSkyBox(){
                return this->sky->getSkyBox();
            }

            scene::ISceneNode* getSkyDome(){
                return this->sky->getSkyDome();
            }

            bool getShowBox(){
                return this->sky->getShowBox();
            }

            bool setShowBox(bool showBox){
                return this->sky->setShowBox(showBox);
            }

            bool draw() {
                return this->sky->draw();
            }

            bool onEvent(EACTIONEVENT event) {
                return this->sky->onEvent(event);
            }
    };
} // business

#endif



