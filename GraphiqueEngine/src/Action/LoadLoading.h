#ifndef GRAPHIQUE_LOAD_VIEW_LOADING_H
#define GRAPHIQUE_LOAD_VIEW_LOADING_H

#include "IGraphiqueAction.h"

namespace graphique
{
    class LoadLoading : public IGraphiqueAction
    {
        public:
            LoadLoading(){};
            virtual ~LoadLoading(){};

            int execute(IGraphiqueEngine *engine) {
                return -1;
            }
    };
} // graphique

#endif





