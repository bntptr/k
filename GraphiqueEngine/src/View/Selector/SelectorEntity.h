#ifndef SELECTORENTITY_H
#define SELECTORENTITY_H

#include "../../Kutility/kutility.h"
#include "ISelectorEntity.h"

namespace graphique
{
    class SelectorEntity : public ISelectorEntity
    {
        protected:
            ISelectorEntity *thisInstance;
            TList<IObjectView>* selection;
        public:
            SelectorEntity(){
                this->thisInstance = this;
                this->selection = new TList<IObjectView>();
            };
            ~SelectorEntity(){};

            ISelectorEntity* add(IObjectView *object) {
                this->selection->addElement(object);
                return this->thisInstance;
            }

            ISelectorEntity* reset() {
                this->selection->reset();
                return this->thisInstance;
            }

            ISelectorEntity* onEvent(EACTIONEVENT event) {
                TList<IObjectView>* L = this->selection;
                for(int i = 0; i < L->size(); i++) {
                    L->getElement(i)->onEvent(event);
                }
                return this->thisInstance;
            }
    };
} // graphique

#endif


