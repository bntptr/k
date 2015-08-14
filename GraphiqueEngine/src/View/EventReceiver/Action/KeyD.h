#ifndef IACTIONKEY_D_H
#define IACTIONKEY_D_H

#include "IKey.h"

namespace graphique
{
    class KeyD : public IKey
    {
        public:
            KeyD(){};
            virtual ~KeyD(){};

            int execute(IView *view) {
                irr::scene::ISceneNode* Terrain = view->getTerrain()->getTerrain();
                // toggle detail map
                Terrain->setMaterialType(
                    Terrain->getMaterial(0).MaterialType == irr::video::EMT_SOLID ?
                    irr::video::EMT_DETAIL_MAP : irr::video::EMT_SOLID);
            }
    };
} // graphique

#endif

