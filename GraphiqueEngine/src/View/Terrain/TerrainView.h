#ifndef TERRAINVIEW_H
#define TERRAINVIEW_H

#include "ITerrainView.h"
#include "Action/IAction.h"
#include "Action/MapDetail.h"
#include "Action/MapTriangle.h"
#include "Action/MapPoint.h"

#include "../Camera/ICamera.h"

namespace graphique
{
    class TerrainView : public ITerrainView
    {
        protected:
            ISceneNodeService *sceneNodeService;
            business::IGroundEntity *ground;
            ISceneNode *node;
            //scene::ITerrainSceneNode* terrain;

            TMap<EACTIONEVENT, terrain::IAction>* keyMap;

        public:
            TerrainView(
                ISceneNodeService *service,
                business::IGroundEntity *ground,
                TMap<EACTIONEVENT, terrain::IAction>* keyMap
            ){
                this->sceneNodeService = service;
                this->ground = ground;
                this->keyMap = keyMap;
            };
            ~TerrainView(){};

            bool build(ICameraService* camera) {
                this->node = this->sceneNodeService->addTerrainSceneNode(
                    -1,
                    this->ground->getPosition(),
                    this->ground->getRotation(),
                    this->ground->getScale(),
                    this->ground->getTexture(),
                    this->ground->getMesh()
                );
                return true;
            }

            /**
             * Actif en cas de camera 2d
             */
            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                return false;
            }

            bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                terrain::IAction *action  = this->keyMap->get(event);

                if (action) {
                    action->execute(this);
                }
                return true;
            }

            business::IGroundEntity* getGroundEntity() {
                return this->ground;
            }

            ISceneNode* getSceneNode() {
                return this->node;
            }
    };
} // graphique

#endif
