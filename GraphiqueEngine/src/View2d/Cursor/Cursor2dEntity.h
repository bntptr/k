#ifndef VIEW_CURSOR_2D_ENTITY_H
#define VIEW_CURSOR_2D_ENTITY_H

#include "Cursor2dConfig.h"
#include "../Camera/Camera2dService.h"

namespace graphique
{
    class Cursor2dEntity : public CursorEntity
    {
        protected:
            IObjectView* selectedObjectView;
            int etat;
            //rectangle de sélection
            int x;
            int y;
            int X;
            int Y;
            //clic
            bool clicg;
            bool clicd;
            //color
            video::SColor colorCursorDefault;
            video::SColor colorCursorAction;
            video::SColor colorLeft;
            video::SColor colorRight;
        public:
            Cursor2dEntity(
                irr::IrrlichtDevice *device,
                IView *view,
                TMap<irr::EMOUSE_INPUT_EVENT, IEmie>* keyMap
            ) : CursorEntity (device, view, keyMap){
                this->etat = CURSOR_DEFAULT;
                this->x = 0;
                this->y = 0;
                this->X = 0;
                this->Y = 0;
                this->clicg = false;
                this->clicd = false;
                this->colorLeft.set(100,200,100,255);
                this->colorRight.set(200,255,100,100);
                this->colorCursorDefault.set(100,200,200,200);
                this->colorCursorAction.set(100,255,100,0);
            };
            ~Cursor2dEntity(){};

            //affiche()
            void affiche(){

                using namespace irr;
                video::IVideoDriver* driver = device->getVideoDriver();

                if (this->clicg) {
                    if (this->x > this->X) {
                        if (this->y > this->Y) {
                            driver->draw2DRectangle(
                                this->colorLeft,
                                core::rect<s32>(
                                    this->X,
                                    this->Y,
                                    this->x,
                                    this->y
                                )
                            );
                        } else {
                            driver->draw2DRectangle(
                                this->colorLeft,
                                core::rect<s32>(
                                    this->X,
                                    this->y,
                                    this->x,
                                    this->Y
                                )
                            );
                        }
                    } else {
                        if (this->y > this->Y) {
                            driver->draw2DRectangle(
                                this->colorLeft,
                                core::rect<s32>(
                                    this->x,
                                    this->Y,
                                    this->X,
                                    this->y
                                )
                            );
                        } else {
                            driver->draw2DRectangle(
                                this->colorLeft,
                                core::rect<s32>(
                                    this->x,
                                    this->y,
                                    this->X,
                                    this->Y
                                )
                            );
                        }
                    }
                    //driver->draw2DRectangle(video::SColor(100,200,100,255),core::rect<s32>(cursor->x, cursor->y, cursor->X, cursor->Y));
                }
                if (this->clicd) {
                    if (this->x > this->X) {
                        if (this->y > this->Y) {
                            driver->draw2DRectangle(
                                this->colorRight,
                                core::rect<s32>(
                                    this->X,
                                    this->Y,
                                    this->x,
                                    this->y
                                )
                            );
                        } else {
                            driver->draw2DRectangle(
                                this->colorRight,
                                core::rect<s32>(
                                    this->X,
                                    this->y,
                                    this->x,
                                    this->Y
                                )
                            );
                        }
                    } else {
                        if (this->y > this->Y) {
                            driver->draw2DRectangle(
                                this->colorRight,
                                core::rect<s32>(
                                    this->x,
                                    this->Y,
                                    this->X,
                                    this->y
                                )
                            );
                        } else {
                            driver->draw2DRectangle(
                                this->colorRight,
                                core::rect<s32>(
                                    this->x,
                                    this->y,
                                    this->X,
                                    this->Y
                                )
                            );
                        }
                    }
                }

                core::position2d<s32> m = device->getCursorControl()->getPosition();
                //Type de cursor
                switch(this->etat) {
                    case CURSOR_CREER_UNITE:
                        // draw transparent rect under cursor
                        //core::position2d<s32> m = device->getCursorControl()->getPosition();
                        driver->draw2DRectangle(
                            this->colorCursorAction,
                            core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20)
                        );
                        break;
                    default:
                        // draw transparent rect under cursor
                        //core::position2d<s32> m = device->getCursorControl()->getPosition();
                        driver->draw2DRectangle(
                            this->colorCursorDefault,
                            core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20)
                        );
                        break;
                }
            }

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
                    core::rect<s32>(this->x, this->y, this->X, this->Y)
                );
                this->affiche();

                return true;
            }

            ICursorEntity* execute(irr::EMOUSE_INPUT_EVENT key) {
                IEmie *k = this->keyMap->get(key);
                if (k) {
                    k->execute(this->view);
                }
                return this->thisInstance;
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

            //Général
            int think(){
                if (this->left->isDown()) {
                    if (!clicg) {
                        x = X;
                        y = Y;
                        clicg = true;
                    }
                    return 0;
                }
                if (this->right->isDown()) {
                    if (!clicd) {
                        x = X;
                        y = Y;
                        clicd = true;
                    }
                    return 0;
                }
                if ((!this->left->isDown()) && (clicg)) {
                    if ((x == X) && (y== Y)) {
                        switch(etat) {
                            //case CURSOR_CREER_UNITE: joueur->addUnite(new Unite(x, y)); resetEtat(); break;
                            case CURSOR_CREER_UNITE:
                            //prt->vue2d->positionnerUnite(x, y, 0);
                            //resetEtat();
                                break;
                            default:
                                //s->actualiseSelect(x, y);
                                break;
                        }
                    } else {
                        switch(this->etat) {
                            case CURSOR_CREER_UNITE:
                                //resetEtat();
                                break;
                            default:
                                //s->actualiseSelect(x, y, X, Y);
                                break;
                        }
                    }
                    clicg = false;
                    return 0;
                }

                if ((!this->right->isDown()) && (clicd)){
                    if((x == X) && (y == Y)) {
                        switch(this->etat) {
                            case CURSOR_CREER_UNITE:
                                //resetEtat();
                                break;
                            default:
                                //s->objectifSelect(x, y);
                                break;
                        }
                    } else {
                        switch(this->etat){
                            case CURSOR_CREER_UNITE:
                                //resetEtat();
                                break;
                            default:
                                //s->objectifSelect(x, y, X, Y);
                                break;
                        }
                    }
                    clicd = false;
                    return 0;
                }
                return -1;
            }

            bool onEvent(const irr::SEvent& event) {
                if (irr::EMIE_MOUSE_MOVED == event.MouseInput.Event) {
                    this->X = event.MouseInput.X; //si marche pas utiliser "core::position2di Position;" dans MyCursor
                    this->Y = event.MouseInput.Y;
                    this->think();
                }
                this->execute(event.MouseInput.Event);
                return true;
            }
    };
} // graphique

#endif


