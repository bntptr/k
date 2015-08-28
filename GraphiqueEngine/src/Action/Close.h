#ifndef GRAPHIQUE_CLOSE_H
#define GRAPHIQUE_CLOSE_H

#include "IGraphiqueAction.h"

namespace graphique
{
    class Close : public IGraphiqueAction
    {
        public:
            Close(){};
            virtual ~Close(){};

            int execute(IGraphiqueEngine *engine) {
                engine->setActive(false);
                engine->exit();
                engine->drop();
                return -1;
            }
    };
} // graphique

#endif





