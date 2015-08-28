#ifndef GRAPHIQUE_IACTION_H
#define GRAPHIQUE_IACTION_H

#include "../IGraphiqueEngine.h"

namespace graphique
{
    class IGraphiqueAction
    {
        public:
            IGraphiqueAction(){};
            virtual ~IGraphiqueAction(){};

            virtual int execute(IGraphiqueEngine *engine) {
                return -1;
            }
    };
} // graphique

#endif


