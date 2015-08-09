#ifndef GRAPHIQUEENGINE_FACTORY_H
#define GRAPHIQUEENGINE_FACTORY_H

#include "GraphiqueEngine.h"

namespace graphique
{
    class GraphiqueEngineFactory
    {
    public:
        static IGraphiqueEngine* createEngine() {
            return new GraphiqueEngine();
        }
    };
} // graphique

#endif
