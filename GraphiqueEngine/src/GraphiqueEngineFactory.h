#ifndef GRAPHIQUEENGINE_FACTORY_H
#define GRAPHIQUEENGINE_FACTORY_H

#include "GraphiqueEngine.h"
#include "Action/Actions.h"

namespace graphique
{
    class GraphiqueEngineFactory
    {
        public:
            static IGraphiqueEngine* createEngine() {
                TMap<EGRAPHIQUE, IGraphiqueAction>* keyMap = new TMap<EGRAPHIQUE, IGraphiqueAction>();
                keyMap->addElement(EGRAPHIQUE_VIEW_LOADING, new LoadLoading());
                keyMap->addElement(EGRAPHIQUE_VIEW_2D, new LoadView2d());
                keyMap->addElement(EGRAPHIQUE_VIEW_3D, new LoadView3d());
                keyMap->addElement(EGRAPHIQUE_CLOSE, new Close());
                return new GraphiqueEngine(keyMap);
            }
    };
} // graphique

#endif
