#ifndef VIEW_CAMERA_SERVICE_H
#define VIEW_CAMERA_SERVICE_H

#include "Camera.h"
#include "ICameraService.h"
#include "CameraFactory.h"

namespace graphique
{
    class CameraService : public ICameraService
    {
        protected:
            ICameraService *thisInstance;
            ICamera *camera;

            irr::IrrlichtDevice *device;
            ICursorService *cursor;

        public:
            CameraService(){
                this->thisInstance = this;
            };
            CameraService(irr::IrrlichtDevice *device, ICursorService *cursor){
                this->thisInstance = this;
                this->device = device;
                this->cursor = cursor;
                this->camera = CameraFactory::createEntity(device, cursor);
            };
            ~CameraService(){};

            irr::scene::ICameraSceneNode* getCameraSceneNode() {
                return this->camera->getCameraSceneNode();
            }

            ICamera* getCamera() {
                return this->camera;
            }

            bool build() {
                return this->camera->build();
            }

            bool draw(ITerrainService *terrain, IPopulationService *population) {
                return this->camera->draw(terrain, population);
            }

            /*bool active2d() {
                std::cout << "2d" << std::endl;
                irr::scene::ISceneManager* smgr = device->getSceneManager();
                this->camera = this->camera2d;
                smgr->setActiveCamera(this->camera->getCameraSceneNode());
                this->cameraFPS->getCameraSceneNode()->setVisible(false);
                this->cameraRTS->getCameraSceneNode()->setVisible(false);
                this->cameraRPG->getCameraSceneNode()->setVisible(false);
                this->cameraEditor->getCameraSceneNode()->setVisible(false);
                return true;
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
                //this->cameraFPS->getCameraSceneNode()->remove();
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
            }*/
    };
} // business

#endif


