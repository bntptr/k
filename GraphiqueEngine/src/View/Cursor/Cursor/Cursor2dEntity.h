#ifndef VIEW_CURSOR_2D_ENTITY_H
#define VIEW_CURSOR_2D_ENTITY_H

#include "Cursor2dConfig.h"
#include "../../Camera/Camera/Camera2dService.h"

namespace graphique
{
    class Cursor2dEntity : public CursorEntity
    {
        protected:
            IObjectView* selectedObjectView;
        public:
            Cursor2dEntity(
                irr::IrrlichtDevice *device,
                IView *view,
                TMap<irr::EMOUSE_INPUT_EVENT, IEmie>* keyMap
            ) : CursorEntity (device, view, keyMap){
            };
            ~Cursor2dEntity(){};

            bool build() {
                std::cout << "Rien car 2D" << std::endl;
            }

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                driver->draw2DRectangle(
                    video::SColor(100,200,100,255),
                    core::rect<s32>(0, 0, 100, 100)
                );

        /*
    if(this->clicg){
                      if(this->x>this->X){
                                              if(this->y>this->Y){
                                                                      prt->driver->draw2DRectangle(video::SColor(100,200,100,255),core::rect<s32>(this->X, this->Y, this->x, this->y));
                                                                      }else{
                                                                            prt->driver->draw2DRectangle(video::SColor(100,200,100,255),core::rect<s32>(this->X, this->y, this->x, this->Y));
                                                                            }
                                              }else{
                                                    if(this->y>this->Y){
                                                                            prt->driver->draw2DRectangle(video::SColor(100,200,100,255),core::rect<s32>(this->x, this->Y, this->X, this->y));
                                                                            }else{
                                                                                  prt->driver->draw2DRectangle(video::SColor(100,200,100,255),core::rect<s32>(this->x, this->y, this->X, this->Y));
                                                                                  }
                                                    }
               //driver->draw2DRectangle(video::SColor(100,200,100,255),core::rect<s32>(cursor->x, cursor->y, cursor->X, cursor->Y));
               }
    if(this->clicd){
                      if(this->x>this->X){
                                              if(this->y>this->Y){
                                                                      prt->driver->draw2DRectangle(video::SColor(200,255,100,100),core::rect<s32>(this->X, this->Y, this->x, this->y));
                                                                      }else{
                                                                            prt->driver->draw2DRectangle(video::SColor(200,255,100,100),core::rect<s32>(this->X, this->y, this->x, this->Y));
                                                                            }
                                              }else{
                                                    if(this->y>this->Y){
                                                                            prt->driver->draw2DRectangle(video::SColor(200,255,100,100),core::rect<s32>(this->x, this->Y, this->X, this->y));
                                                                            }else{
                                                                                  prt->driver->draw2DRectangle(video::SColor(200,255,100,100),core::rect<s32>(this->x, this->y, this->X, this->Y));
                                                                                  }
                                                    }


               }

    core::position2d<s32> m = prt->device->getCursorControl()->getPosition();
    //Type de cursor
    switch(this->etat){
                         case CURSOR_CREER_UNITE:
                              // draw transparent rect under cursor
                              //core::position2d<s32> m = device->getCursorControl()->getPosition();
                              prt->driver->draw2DRectangle(video::SColor(100,255,100,0),
                              core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20)); break;
                         default:
                                  // draw transparent rect under cursor
                              //core::position2d<s32> m = device->getCursorControl()->getPosition();
                              prt->driver->draw2DRectangle(video::SColor(100,200,200,200),
                              core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20));break;
                         }

                     //}
*/
                return true;
            }

            ICursorEntity* execute(irr::EMOUSE_INPUT_EVENT key) {
                IEmie *k = this->keyMap->get(key);
                if (k) {
                    k->execute(this->view);
                }
                return this->thisInstance;
            }

            bool onEvent(const irr::SEvent& event) {
                this->execute(event.MouseInput.Event);
                return true;
            }

            irr::scene::ITriangleSelector* getSelector() {
                return this->selector;
            }

            int getSelectedSceneNodeId() {
                if (this->selectedObjectView)
                    return -1;//this->selectedObjectView->getID();
                else
                    return -1;
            }

            ICursorEntity* setCameraService(ICameraService *camera) {
                this->camera = camera;
                ICursorEntity* thisInstance = this;
                return thisInstance;
            }

            IMouseButton* getLeft() {
                return this->left;
            }

            IMouseButton* getRight() {
                return this->right;
            }
    };
} // graphique

#endif


