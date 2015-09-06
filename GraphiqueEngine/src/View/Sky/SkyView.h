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
            ISceneNodeService *sceneNodeService;
            business::ISkyEntity *skyEntity;
            ISceneNode *skybox;
            ISceneNode *skydome;
            bool showBox;

            TMap<EACTIONEVENT, sky::IAction>* keyMap;

        public:
            SkyView(
                ISceneNodeService *service,
                business::ISkyEntity *skyEntity,
                TMap<EACTIONEVENT, sky::IAction>* keyMap
            ){
                this->sceneNodeService = service;
                this->skyEntity = skyEntity;
                this->showBox = true;
                this->keyMap = keyMap;
            };
            ~SkyView(){};

            ISceneNode* getSkyBox(){
                return this->skybox;
            }

            ISceneNode* getSkyDome(){
                return this->skydome;
            }

            bool getShowBox(){
                return this->showBox;
            }

            void updateShowBox(){
                this->showBox =! this->showBox;
                this->skybox->setVisible(this->showBox);
                this->skydome->setVisible(!this->showBox);
            }

            bool setShowBox(bool showBox){
                return this->showBox = showBox;
            }

            bool build() {
                this->skybox = this->sceneNodeService->addSkyBoxSceneNode(
                    this->skyEntity->getTextureSkyBoxUp(),
                    this->skyEntity->getTextureSkyBoxDn(),
                    this->skyEntity->getTextureSkyBoxLf(),
                    this->skyEntity->getTextureSkyBoxRt(),
                    this->skyEntity->getTextureSkyBoxFt(),
                    this->skyEntity->getTextureSkyBoxBk()
                );
                this->skydome = this->sceneNodeService->addSkyDomeSceneNode(
                    this->skyEntity->getTextureSkyDome()
                );
                return true;
            }

            bool draw() {
                return true;
            }

            bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                sky::IAction *action  = this->keyMap->get(event);

                if (action) {
                    action->execute(this);
                }
                return true;
            }

            business::ISkyEntity* getSkyEntity() {
                return this->skyEntity;
            }
    };
} // graphique

#endif
