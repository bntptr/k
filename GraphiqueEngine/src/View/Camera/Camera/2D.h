#ifndef TWO_D_CAMERA_H
#define TWO_D_CAMERA_H

#include "../Camera.h"

namespace graphique
{
    class Camera2D : public Camera
    {
        protected:
            business::Vector3d position;
            business::Vector3d scale;

        public:
            Camera2D(irr::IrrlichtDevice *device, ICursorService *cursor) : Camera(device, cursor){
                this->setPosition(business::Vector3d(0,0,0));
                this->setScale(business::Vector3d(500,0,500));
            };
            ~Camera2D(){};

            bool build() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add camera
                this->camera =
                    smgr->addCameraSceneNode();
                //this->camera->setPosition(core::vector3df(0,0,30));
                //this->camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
                //this->camera->setFarValue(42000.0f);

                this->camera->setVisible(true);

                // mouse cursor
                device->getCursorControl()->setVisible(true);

                using namespace core;
                // Crée trois caméras fixes et une contrôlée par l'utilisateur.
                // Devant
                this->cameras[0] = smgr->addCameraSceneNode(0, vector3df(50,0,0), vector3df(0,0,0));
                // Dessus
                this->cameras[1] = smgr->addCameraSceneNode(0, vector3df(0,50,0), vector3df(0,0,0));
                // Gauche
                this->cameras[2] = smgr->addCameraSceneNode(0, vector3df(0,0,50), vector3df(0,0,0));
                // Contrôlée par l'utilisateur.
                this->cameras[3] = smgr->addCameraSceneNodeFPS();
                // Ne commence pas à la position de Sydney.
                if (this->cameras[3])
                    this->cameras[3]->setPosition(core::vector3df(-50,0,-50));
                this->device->getCursorControl()->setVisible(false);
                return true;
            }

            bool draw(ITerrainService *terrain, IPopulationService *population) {
                using namespace irr;
                using namespace core;
                ViewConfig *config = ViewConfig::getInstance();
                int ResX=800;
                int ResY=600;
                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = this->device->getVideoDriver();
                scene::ISceneManager* smgr = this->device->getSceneManager();

                // Définit la zone de rendu sur la totalité de l'écran et commence la scène.
                driver->setViewPort(rect<s32>(0, 0, ResX, ResY));
                driver->beginScene(true,true,video::SColor(255,100,100,100));
                // Si la division d'écran est utilisée.
                if (this->splitScreen)
                {
                    // Active la caméra 1.
                    //smgr->setActiveCamera(this->cameras[0]);
                    // Définit la zone de rendu sur le premier quart (en haut à gauche).
                    //driver->setViewPort(rect<s32>(0,0,ResX/2,ResY/2));
                    // Dessine la scène.
                    //smgr->drawAll();
                    // Active la caméra 2.
                    smgr->setActiveCamera(this->cameras[1]);
                    // Définit la zone de rendu sur le deuxième quart (en haut à droite).
                    driver->setViewPort(rect<s32>(ResX/2,0,ResX,ResY/2));
                    // Dessine la scène.
                    smgr->drawAll();
                    // Active la caméra 3.
                    smgr->setActiveCamera(this->cameras[2]);
                    // Définit la zone de rendu sur le troisième quart (en bas à gauche).
                    driver->setViewPort(rect<s32>(0,ResY/2,ResX/2,ResY));
                    // Dessine la scène.
                    smgr->drawAll();
                    // définit la zone de rendu sur le dernier quart (en bas à droite )
                    driver->setViewPort(rect<s32>(ResX/2,ResY/2,ResX,ResY));
                }
                // Active la caméra 4.
                smgr->setActiveCamera(this->cameras[3]);

                terrain->draw(this->getPosition(), this->getScale());
                //population->draw();
            }

            business::Vector3d getPosition(){
                return this->position;
            }

            Camera2D* setPosition(business::Vector3d position) {
                this->position = position;
                return this;
            }

            business::Vector3d getScale(){
                return this->scale;
            }

            Camera2D* setScale(business::Vector3d scale){
                this->scale = scale;
                return this;
            }
    };
} // graphique

#endif

