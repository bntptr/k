#ifndef SELECTORSERVICE_H
#define SELECTORSERVICE_H

#include "../IObjectView.h"
#include "../IView.h"

#include "SelectorEntity.h"
#include "ISelectorService.h"

namespace graphique
{
    class SelectorService : public ISelectorService
    {
        protected:
            ISelectorService* thisInstance;
            ISelectorEntity* cursorLeft;
            ISelectorEntity* cursorRight;

        public:
            SelectorService(){
                this->thisInstance = this;
                this->cursorLeft = new SelectorEntity();
                this->cursorRight = new SelectorEntity();
            };
            ~SelectorService(){};

            ISelectorEntity* getCursorLeft() {
                return this->cursorLeft;
            }

            ISelectorEntity* getCursorRight() {
                return this->cursorRight;
            }

            ISelectorService* resetCursorLeft() {
                this->cursorLeft->reset();
                return this->thisInstance;
            }

            ISelectorService* resetCursorRight() {
                this->cursorRight->reset();
                return this->thisInstance;
            }

            ISelectorService* addToCursorLeft(IObjectView *obj) {
                this->cursorLeft->add(obj);
                return this->thisInstance;
            }

            ISelectorService* addToCursorRight(IObjectView *obj) {
                this->cursorRight->add(obj);
                return this->thisInstance;
            }

            ISelectorService* selectLeft(IView *view) {
                int id = view->getCursor()->getSelectedSceneNodeId();
                IObjectView *obj = view->getPopulation()->getObjectViewFromId(id);
                this->addToCursorLeft(obj);
                return this->thisInstance;
            }

            ISelectorService* oneEventSelectorRight(EACTIONEVENT event) {
                this->cursorRight->oneEvent(event);
                return this->thisInstance;
            }

            ISelectorService* oneEventSelectorLeft(EACTIONEVENT event) {
                this->cursorLeft->oneEvent(event);
                return this->thisInstance;
            }
    };
} // business

#endif
