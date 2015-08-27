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
                int id = view->getCursorService()->getSelectedSceneNodeId();std::cout <<"id selected "<< id <<std::endl;
                if (0 < id) {
                    this->resetCursorLeft();
                    IObjectView *obj = view->getPopulation()->getObjectViewFromId(id);if (obj) {std::cout <<"obj " <<std::endl;}else{std::cout <<"not obj" <<std::endl;}
                    this->addToCursorLeft(obj);
                } else {
                    this->resetCursorLeft();
                }
                return this->thisInstance;
            }

            ISelectorService* onEventSelectorRight(EACTIONEVENT event) {
                this->cursorRight->onEvent(event);
                return this->thisInstance;
            }

            ISelectorService* onEventSelectorLeft(EACTIONEVENT event) {std::cout <<"coucou"<<std::endl;
                this->cursorLeft->onEvent(event);
                return this->thisInstance;
            }
    };
} // business

#endif
