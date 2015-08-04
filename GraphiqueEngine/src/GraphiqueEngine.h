#ifndef GRAPHIQUEENGINE_H
#define GRAPHIQUEENGINE_H

#include "IGraphiqueEngine.h"
#include "GraphiqueEngineFactory.h"
//#include "View/ViewEventReceiver.h"

class IController;

namespace graphique
{
    class GraphiqueEngine : public IGraphiqueEngine
    {
        public:
            GraphiqueEngine() {
            };
            ~GraphiqueEngine() {
            };

            static IGraphiqueEngine* createEngine()
            {
                IGraphiqueEngine *engine = new GraphiqueEngine();
                return engine;
            }

            bool run();
            bool drop();
            bool start();
            bool exit();

            BusinessInterface* getBusiness();
            IGraphiqueEngine* setBusiness(BusinessInterface *business);
            IView* getView();
            IGraphiqueEngine* setView(IView *view);

        protected:
            BusinessInterface *business;
            IView *view;
            IController *controller;
            //ViewEventReceiver *eventReceiver;
        private:
    };

    bool GraphiqueEngine::start()
    {
        if (this->view) {
            this->view->init();

            if (this->business) {
                return this->view->build(this->business);
            }

            this->view->error();
        }
        return false;
    }

    bool GraphiqueEngine::run()
    {
        if (this->view) {
            this->view->run();
        }
        return true;
    }

    bool GraphiqueEngine::exit()
    {
        if (this->view) {
            //this->view->exit();
        }
        return true;
    }

    bool GraphiqueEngine::drop()
    {
        return true;
    }

    BusinessInterface* GraphiqueEngine::getBusiness()
    {
        return this->business;
    }

    IGraphiqueEngine* GraphiqueEngine::setBusiness(BusinessInterface *business)
    {
        this->business = business;
        IGraphiqueEngine *engine = this;
        return engine;
    }

    IView* GraphiqueEngine::getView()
    {
        return this->view;
    }

    IGraphiqueEngine* GraphiqueEngine::setView(IView *view)
    {
        this->view = view;
        IGraphiqueEngine *engine = this;
        return engine;
    }
}
#endif // GRAPHIQUEENGINE_H
