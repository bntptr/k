#ifndef IACTIONKEY_Q_H
#define IACTIONKEY_Q_H

#include "IKey.h"

namespace graphique
{
    class KeyQ : public IKey
    {
        public:
            KeyQ(){};
            virtual ~KeyQ(){};

            int execute(IView *view) {
                irr::scene::ISceneNode* Terrain = view->getTerrain()->getTerrain();
                // switch wire frame mode
                Terrain->setMaterialFlag(irr::video::EMF_WIREFRAME,
                        !Terrain->getMaterial(0).Wireframe);
                Terrain->setMaterialFlag(irr::video::EMF_POINTCLOUD, false);
            }
    };
} // graphique

#endif


