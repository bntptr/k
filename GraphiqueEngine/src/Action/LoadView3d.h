#ifndef GRAPHIQUE_LOAD_VIEW_3D_H
#define GRAPHIQUE_LOAD_VIEW_3D_H

#include "IGraphiqueAction.h"

namespace graphique
{
    class LoadView3d : public IGraphiqueAction
    {
        public:
            LoadView3d(){};
            virtual ~LoadView3d(){};

            int execute(IGraphiqueEngine *engine) {
                return -1;
            }
    };
} // graphique

#endif





