#ifndef VIEW_SPHERE_SCENE_NODE_H
#define VIEW_SPHERE_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class SphereSceneNode : public SceneNode
    {
        public:
            SphereSceneNode(irr::IrrlichtDevice *device) : SceneNode() {
                this->device = device;
            };
            ~SphereSceneNode(){};

            bool build(ICameraService* camera) {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();

                // SPHERE
                scene::ISceneNode * node3 = smgr->addSphereSceneNode();
                if (node3)
                {
                    node3->setPosition(core::vector3df(0,0,30));
                    node3->setMaterialTexture(0, driver->getTexture(MEDIA + "wall.bmp"));
                    node3->setMaterialFlag(video::EMF_LIGHTING, false);
                }
                return true;
            }

            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                return true;
            }

            bool onEvent(const irr::SEvent& event) {
                return true;
            }
    };
} // graphique

#endif
