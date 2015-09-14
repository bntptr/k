#ifndef VIEW_CUBE_SCENE_NODE_H
#define VIEW_CUBE_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class CubeSceneNode : public SceneNode
    {
        public:
            CubeSceneNode(irr::IrrlichtDevice *device) : SceneNode() {
                this->device = device;
            };
            ~CubeSceneNode(){};

            bool build(ICameraService* camera) {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                //CUBE
                scene::ISceneNode* n = smgr->addCubeSceneNode();

                if (n)
                {
                    n->setMaterialTexture(0, driver->getTexture(MEDIA + "t351sml.jpg"));
                    n->setMaterialFlag(video::EMF_LIGHTING, false);
                    scene::ISceneNodeAnimator* anim =
                        smgr->createFlyCircleAnimator(core::vector3df(0,0,30), 20.0f);
                    if (anim)
                    {
                        n->addAnimator(anim);
                        anim->drop();
                    }
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
