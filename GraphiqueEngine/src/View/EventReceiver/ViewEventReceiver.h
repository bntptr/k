#ifndef VIEWEVENTRECEIVER_H
#define VIEWEVENTRECEIVER_H

#include <irrlicht.h>
#include <iostream>
#include "Action/KeyW.h"

using namespace irr;

namespace graphique
{
    class ViewEventReceiver : public IEventReceiver
    {
        public:
            ViewEventReceiver(scene::ISceneNode* terrain, scene::ISceneNode* skybox, scene::ISceneNode* skydome) :
                Terrain(terrain), Skybox(skybox), Skydome(skydome), showBox(true)
            {
                Skybox->setVisible(true);
                Skydome->setVisible(false);
            }

            bool OnEvent(const SEvent& event)
            {
                if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown)
                {
                    IKey *key;
                    switch (event.KeyInput.Key)
                    {
                    case irr::KEY_KEY_Q: // switch wire frame mode
                        Terrain->setMaterialFlag(video::EMF_WIREFRAME,
                                !Terrain->getMaterial(0).Wireframe);
                        Terrain->setMaterialFlag(video::EMF_POINTCLOUD, false);
                        return true;
                    case irr::KEY_KEY_F: // switch wire frame mode
                        Terrain->setMaterialFlag(video::EMF_POINTCLOUD,
                                !Terrain->getMaterial(0).PointCloud);
                        Terrain->setMaterialFlag(video::EMF_WIREFRAME, false);
                        return true;
                    case irr::KEY_KEY_D: // toggle detail map
                        Terrain->setMaterialType(
                            Terrain->getMaterial(0).MaterialType == video::EMT_SOLID ?
                            video::EMT_DETAIL_MAP : video::EMT_SOLID);
                        return true;
                    case irr::KEY_KEY_S: // toggle skies
                        showBox=!showBox;
                        Skybox->setVisible(showBox);
                        Skydome->setVisible(!showBox);
                        return true;

                    case irr::KEY_KEY_W:
                        key = new KeyW();
                        key->execute(this->view);
                        return true;
                    case irr::KEY_KEY_X:
                        //this->actionKeyService->execute(EACTIONKEY_X);
                        return true;
                    case irr::KEY_KEY_C:
                        return true;
                    case irr::KEY_KEY_V:
                        return true;
                    default:
                        break;
                    }
                }

                return false;
            }

            ViewEventReceiver* setView(IView *view) {
                this->view = view;
                return this;
            }

        private:
            scene::ISceneNode* Terrain;
            scene::ISceneNode* Skybox;
            scene::ISceneNode* Skydome;
            bool showBox;

            IView* view;
    };
}

#endif

