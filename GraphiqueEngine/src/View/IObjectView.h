#ifndef IOBJECTVIEW_H
#define IOBJECTVIEW_H

#include "../Business/Event/EActionEvent.h"

namespace graphique
{
    class IObjectView
    {
        protected:
            int id;
        public:
            IObjectView(){};
            virtual ~IObjectView(){};

            int getId() {
                return this->id;
            }

            int setId(int id) {
                return this->id = id;
            }

            virtual bool oneEvent(EACTIONEVENT event)=0;
    };
} // graphique

#endif


