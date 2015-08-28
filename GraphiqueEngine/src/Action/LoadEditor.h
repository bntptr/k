#ifndef GRAPHIQUE_LOAD_EDITOR_H
#define GRAPHIQUE_LOAD_EDITOR_H

#include "IGraphiqueAction.h"

namespace graphique
{
    class LoadEditor : public IGraphiqueAction
    {
        public:
            LoadEditor(){};
            virtual ~LoadEditor(){};

            int execute(IGraphiqueEngine *engine) {
                return -1;
            }
    };
} // graphique

#endif





