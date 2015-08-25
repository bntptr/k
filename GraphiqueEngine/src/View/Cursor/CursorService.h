#ifndef CURSOR_SERVICE_H
#define CURSOR_SERVICE_H

#include "CursorFactory.h"
#include "ICursorService.h"

namespace graphique
{
    class CursorService : public ICursorService
    {
        protected:
            ICursorService *thisInstance;
            ICursorEntity *cursor;

        public:
            CursorService(irr::IrrlichtDevice *device, IView *view){
                this->thisInstance = this;
                this->cursor = CursorFactory::createEntity(device, view);
            };
            ~CursorService(){};

            bool build() {
                return this->cursor->build();
            }

            bool draw() {
                return this->cursor->draw();
            }

            ICursorEntity* execute(irr::EMOUSE_INPUT_EVENT key) {
                return this->cursor->execute(key);
            }

            bool oneEvent(const irr::SEvent& event) {
                return this->cursor->oneEvent(event);
            }

            irr::scene::ITriangleSelector* getSelector() {
                return this->cursor->getSelector();
            }

            int getSelectedSceneNodeId() {
                return this->cursor->getSelectedSceneNodeId();
            }

            ICursorEntity* setCameraService(ICameraService *camera) {
                return this->cursor->setCameraService(camera);
            }

            IMouseButton* getLeft() {
                return this->cursor->getLeft();
            }

            IMouseButton* getRight() {
                return this->cursor->getRight();
            }
    };
} // business

#endif



