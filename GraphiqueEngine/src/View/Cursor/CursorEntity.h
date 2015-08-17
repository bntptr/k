#ifndef VIEW_CURSOR_ENTITY_H
#define VIEW_CURSOR_ENTITY_H

#include "CursorConfig.h"
#include "ICursorEntity.h"
#include "../ViewConfig.h"
//#include "Action/IAction.h"

namespace graphique
{
    class CursorEntity : public ICursorEntity
    {
        protected:
            irr::IrrlichtDevice *device;
            scene::ITriangleSelector* selector;

        public:
            CursorEntity(irr::IrrlichtDevice *device){
                this->device = device;
            };
            ~CursorEntity(){};

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();


                this->selector = 0;

                //////**************************************

                // Set a jump speed of 3 units per second, which gives a fairly realistic jump
                // when used with the gravity of (0, -10, 0) in the collision response animator.
                /*scene::ICameraSceneNode* camera =
                    smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, ID_IsNotPickable, 0, 0, true, 3.f);
                camera->setPosition(core::vector3df(50,50,-60));
                camera->setTarget(core::vector3df(-70,30,-60));

                if (selector)
                {
                    scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
                        selector, camera, core::vector3df(30,50,30),
                        core::vector3df(0,-10,0), core::vector3df(0,30,0));
                    selector->drop(); // As soon as we're done with the selector, drop it.
                    camera->addAnimator(anim);
                    anim->drop();  // And likewise, drop the animator when we're done referring to it.
                }*/
                // Now I create three animated characters which we can pick, a dynamic light for
                // lighting them, and a billboard for drawing where we found an intersection.

                // First, let's get rid of the mouse cursor.  We'll use a billboard to show
                // what we're looking at.
                device->getCursorControl()->setVisible(false);

            }

            bool oneEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                //sky::IAction *action;
                switch(event)
                {
                    case EACTIONEVENT_CHANGE_SKY:
                        //action = new building::Build();
                        //action->execute(this);
                        break;
                    default:
                    break;
                }
                return true;
            }

            scene::ITriangleSelector* getSelector() {
                return this->selector;
            }
    };
} // graphique

#endif


