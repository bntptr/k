#ifndef VIEW_SELECTOR_SERVICE_FACTORY_H
#define VIEW_SELECTOR_SERVICE_FACTORY_H

#include "SelectorService.h"

namespace graphique
{
    class SelectorServiceFactory
    {
        public:
            static ISelectorService* createService() {
                return new SelectorService();
            }
    };
} // graphique

#endif




