#ifndef VIEW_ICURSOR_ENTITY_H
#define VIEW_ICURSOR_ENTITY_H

#include <irrlicht.h>
#include "Button/IMouseButton.h"
#include "../Camera/ICameraService.h"

namespace graphique
{
    class ICursorEntity
    {
        public:
            ICursorEntity(){};
            virtual ~ICursorEntity(){};

            virtual bool build()=0;
            virtual bool draw()=0;
            virtual ICursorEntity* execute(irr::EMOUSE_INPUT_EVENT key)=0;
            virtual bool oneEvent(const irr::SEvent& event)=0;

            virtual irr::scene::ITriangleSelector* getSelector()=0;
            virtual int getSelectedSceneNodeId()=0;
            virtual ICursorEntity* setCameraService(ICameraService *camera)=0;

            virtual IMouseButton* getLeft()=0;
            virtual IMouseButton* getRight()=0;
    };
} // graphique

#endif


