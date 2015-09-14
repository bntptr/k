#ifndef VIEW_SELECTOR_ENTITY_FACTORY_H
#define VIEW_SELECTOR_ENTITY_FACTORY_H

#include "SelectorEntity.h"

namespace graphique
{
    class SelectorEntityFactory
    {
        public:
            static ISelectorEntity* createEntity() {
                return new SelectorEntity();
            }
    };
} // graphique

#endif


