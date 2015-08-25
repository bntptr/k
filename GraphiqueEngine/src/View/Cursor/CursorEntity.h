#ifndef VIEW_CURSOR_ENTITY_H
#define VIEW_CURSOR_ENTITY_H

#include "CursorConfig.h"
#include "Button/MouseButton.h"
#include "ICursorEntity.h"
#include "Action/Actions.h"
#include "../ViewConfig.h"
//#include "Action/IAction.h"
#include "../Camera/ICameraService.h"

namespace graphique
{
    class CursorEntity : public ICursorEntity
    {
        protected:
            irr::IrrlichtDevice *device;
            irr::scene::ITriangleSelector* selector;
            irr::scene::IBillboardSceneNode * bill;
            irr::scene::ISceneNode* highlightedSceneNode;
            irr::scene::ISceneNode* selectedSceneNode;
            irr::scene::ISceneCollisionManager* collMan;
            ICameraService *camera;

            ICursorEntity *thisInstance;
            IMouseButton *left;
            IMouseButton *right;
            TMap<irr::EMOUSE_INPUT_EVENT, IEmie>* keyMap;
            IView *view;


        public:
            CursorEntity(irr::IrrlichtDevice *device, IView *view, TMap<irr::EMOUSE_INPUT_EVENT, IEmie>* keyMap){
                this->thisInstance = this;
                this->device = device;
                this->keyMap = keyMap;
                this->view = view;
                this->left = new MouseButton();
                this->right = new MouseButton();
            };
            ~CursorEntity(){};

            bool build() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                device->getCursorControl()->setVisible(CURSOR_VISIBLE);

                // Add the billboard.//panneau d'affichage
                scene::IBillboardSceneNode * bill = smgr->addBillboardSceneNode();
                bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR );
                bill->setMaterialTexture(0, driver->getTexture("../../../media/particle.bmp"));//le truc rouge :)
                bill->setMaterialFlag(video::EMF_LIGHTING, false);
                bill->setMaterialFlag(video::EMF_ZBUFFER, false);
                bill->setSize(core::dimension2d<f32>(20.0f, 20.0f));
                bill->setID(ID_IsNotPickable); // This ensures that we don't accidentally ray-pick it

                // Add a light, so that the unselected nodes aren't completely dark.
                scene::ILightSceneNode * light = smgr->addLightSceneNode(
                    0,
                    core::vector3df(-60,100,400),
                    video::SColorf(1.0f,1.0f,1.0f,1.0f),
                    600.0f
                );
                light->setID(ID_IsNotPickable); // Make it an invalid target for selection.

                this->collMan = smgr->getSceneCollisionManager();
                this->bill = bill;

                // Remember which scene node is highlighted
                this->highlightedSceneNode = 0;

                // Remember which scene node is selected
                this->selector = 0;

            }

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                video::SMaterial material;
                //material.setTexture(0, driver->getTexture("../../../media/faerie3.bmp"));
                //material.Lighting = true;
                //material.NormalizeNormals = true;

                // Unlight any currently highlighted scene node
                if (this->highlightedSceneNode)
                {
                    this->highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, true);
                    this->highlightedSceneNode = 0;
                }

                // All intersections in this example are done with a ray cast out from the camera to
                // a distance of 1000.  You can easily modify this to check (e.g.) a bullet
                // trajectory or a sword's position, or create a ray from a mouse click position using
                // ISceneCollisionManager::getRayFromScreenCoordinates()
                core::line3d<f32> ray;
                ray.start = this->camera->getCamera()->getPosition();
                ray.end = ray.start + (this->camera->getCamera()->getTarget() - ray.start).normalize() * 10000.0f;

                // Tracks the current intersection point with the level or a mesh
                core::vector3df intersection;
                // Used to show with triangle has been hit
                core::triangle3df hitTriangle;

                // This call is all you need to perform ray/triangle collision on every scene node
                // that has a triangle selector, including the Quake level mesh.  It finds the nearest
                // collision point/triangle, and returns the scene node containing that point.
                // Irrlicht provides other types of selection, including ray/triangle selector,
                // ray/box and ellipse/triangle selector, plus associated helpers.
                // See the methods of ISceneCollisionManager
                this->selectedSceneNode =
                    collMan->getSceneNodeAndCollisionPointFromRay(
                            ray,
                            intersection, // This will be the position of the collision
                            hitTriangle, // This will be the triangle hit in the collision
                            false,//IDFlag_IsPickable, // This ensures that only nodes that we have
                                    // set up to be pickable are considered
                            0); // Check the entire scene (this is actually the implicit default)

                // If the ray hit anything, move the billboard to the collision position
                // and draw the triangle that was hit.
                if(this->selectedSceneNode)
                {
                    this->bill->setPosition(intersection);

                    // We need to reset the transform before doing our own rendering.
                    driver->setTransform(video::ETS_WORLD, core::matrix4());
                    driver->setMaterial(material);
                    driver->draw3DTriangle(hitTriangle, video::SColor(0,255,0,0));

                    // We can check the flags for the scene node that was hit to see if it should be
                    // highlighted. The animated nodes can be highlighted, but not the Quake level mesh
                    //if((selectedSceneNode->getID() & IDFlag_IsHighlightable) == IDFlag_IsHighlightable)
                    if(0 < this->selectedSceneNode->getID())
                    {
                        highlightedSceneNode = this->selectedSceneNode;

                        // Highlighting in this case means turning lighting OFF for this node,
                        // which means that it will be drawn with full brightness.
                        highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
                        std::cout << "selected : " << this->selectedSceneNode->getID() << std::endl;
                        std::cout << "intersection : " << intersection.X << ", "<< intersection.Y << ", "<< intersection.Z << std::endl;
                    } else {
                        std::cout << "No selected : " << this->selectedSceneNode->getID() << std::endl;
                    }
                }

                return true;
            }

            ICursorEntity* execute(irr::EMOUSE_INPUT_EVENT key) {
                IEmie *k = this->keyMap->get(key);
                if (k) {
                    k->execute(this->view);
                }
                return this->thisInstance;
            }

            bool oneEvent(const irr::SEvent& event) {
                this->execute(event.MouseInput.Event);
                return true;
            }

            irr::scene::ITriangleSelector* getSelector() {
                return this->selector;
            }

            int getSelectedSceneNodeId() {
                if (this->selectedSceneNode)
                    return this->selectedSceneNode->getID();
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


