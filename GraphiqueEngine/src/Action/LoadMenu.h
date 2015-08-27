#ifndef GRAPHIQUE_LOAD_VIEW_MENU_H
#define GRAPHIQUE_LOAD_VIEW_MENU_H

#include "IGraphiqueAction.h"

namespace graphique
{
    class LoadMenu : public IGraphiqueAction
    {
        public:
            LoadMenu(){};
            virtual ~LoadMenu(){};

            int execute(IGraphiqueEngine *engine) {
                return -1;
            }
    };
} // graphique

#endif





