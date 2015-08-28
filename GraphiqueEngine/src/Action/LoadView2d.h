#ifndef GRAPHIQUE_LOAD_VIEW_2D_H
#define GRAPHIQUE_LOAD_VIEW_2D_H

#include "IGraphiqueAction.h"
#include "../View/View/View2dFactory.h"

namespace graphique
{
    class LoadView2d : public IGraphiqueAction
    {
        public:
            LoadView2d(){};
            virtual ~LoadView2d(){};

            int execute(IGraphiqueEngine *engine) {
                IView *sauv = engine->getView();
                engine->setView(
                    View2dFactory::createEntity(engine->getView())
                );
                return -1;
            }
    };
} // graphique

#endif





