#ifndef VIEW_CAMERA_3D_SERVICE_H
#define VIEW_CAMERA_3D_SERVICE_H

#include "../CameraService.h"
#include "CameraFPSFactory.h"
#include "CameraRTSFactory.h"
#include "CameraRPGFactory.h"
#include "CameraEditorFactory.h"

namespace graphique
{
    class Camera3dService : public CameraService
    {
        protected:
            ICamera *cameraFPS;
            ICamera *cameraRTS;
            ICamera *cameraRPG;
            ICamera *cameraEditor;

        public:
            Camera3dService(irr::IrrlichtDevice *device, ICursorService *cursor){
                this->thisInstance = this;
                this->device = device;
                this->cursor = cursor;
                this->camera = CameraFactory::createEntity(device, cursor);
                this->cameraFPS = CameraFPSFactory::createEntity(this->device, this->cursor);
                this->cameraRTS = CameraRTSFactory::createEntity(this->device, this->cursor);
                this->cameraRPG = CameraRPGFactory::createEntity(this->device, this->cursor);
                this->cameraEditor = this->camera;
            };
            ~Camera3dService(){};

            bool build() {
                this->cameraFPS->build();
                this->cameraRTS->build();
                this->cameraRPG->build();
                return this->camera->build();
            }

            bool draw(ITerrainService *terrain, IPopulationService *population) {
                return this->camera->draw(terrain, population);
            }

            bool activeFPS() {
                std::cout << "FPS" << std::endl;
                irr::scene::ISceneManager* smgr = device->getSceneManager();
                this->camera = this->cameraFPS;
                this->cameraFPS->getCameraSceneNode()->setVisible(true);
                smgr->setActiveCamera(this->cameraFPS->getCameraSceneNode());
                return true;
            }

            bool activeRTS() {
                std::cout << "RTS" << std::endl;
                this->camera = this->cameraRTS;
                irr::scene::ISceneManager* smgr = device->getSceneManager();
                smgr->setActiveCamera(this->camera->getCameraSceneNode());
                this->cameraFPS->getCameraSceneNode()->setVisible(false);
                return true;
            }

            bool activeRPG() {
                std::cout << "RPG" << std::endl;
                this->camera = this->cameraRPG;
                irr::scene::ISceneManager* smgr = device->getSceneManager();
                smgr->setActiveCamera(this->camera->getCameraSceneNode());
                this->cameraFPS->getCameraSceneNode()->setVisible(false);
                return true;
            }

            bool activeEditor() {
                std::cout << "Editor" << std::endl;
                this->camera = this->cameraEditor;
                irr::scene::ISceneManager* smgr = device->getSceneManager();
                smgr->setActiveCamera(this->camera->getCameraSceneNode());
                this->cameraFPS->getCameraSceneNode()->setVisible(false);
                return true;
            }
    };
} // business

#endif


