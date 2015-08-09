#ifndef SELECTORSERVICE_H
#define SELECTORSERVICE_H

#include "../IObjectView.h"

#include "SelectorEntity.h"

namespace graphique
{
    class SelectorService
    {
        protected:
            ISelectorEntity* cursorLeft;
            ISelectorEntity* cursorRight;
        public:
            SelectorService(){
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

            SelectorService* resetCursorLeft() {
                this->cursorLeft->reset();
                return this;
            }

            SelectorService* resetCursorRight() {
                this->cursorRight->reset();
                return this;
            }

            SelectorService* addToCursorLeft(IObjectView *obj) {
                this->cursorLeft->add(obj);
                return this;
            }

            SelectorService* addToCursorRight(IObjectView *obj) {
                this->cursorRight->add(obj);
                return this;
            }

            SelectorService* oneEventSelectorRight(EACTIONEVENT event) {
                this->cursorRight->oneEvent(event);
                return this;
            }

            SelectorService* oneEventSelectorLeft(EACTIONEVENT event) {
                this->cursorLeft->oneEvent(event);
                return this;
            }
    };
} // business

#endif
