#ifndef GRAPHIQUEENGINE_H
#define GRAPHIQUEENGINE_H

#include "IGraphiqueEngine.h"
#include "Action/Actions.h"

//class IController;

namespace graphique
{
    class GraphiqueEngine : public IGraphiqueEngine
    {
        protected:
            TMap<EGRAPHIQUE, IGraphiqueAction>* keyMap;
            business::BusinessInterface *business;
            IView *view;
            bool active;
            //IController *controller;
        public:
            GraphiqueEngine() {
                this->keyMap = new TMap<EGRAPHIQUE, IGraphiqueAction>();
                this->active = true;
            };
            GraphiqueEngine(TMap<EGRAPHIQUE, IGraphiqueAction>* keyMap) {
                this->keyMap = keyMap;
                this->active = true;
            };
            ~GraphiqueEngine() {

            };

            /// OBSOLETE ? 27/08/2015
            static IGraphiqueEngine* createEngine()
            {
                IGraphiqueEngine *engine = new GraphiqueEngine();
                return engine;
            }

            bool run();
            bool drop();
            bool start();
            bool exit();

            bool isActive();
            bool setActive(bool active);

            void execute(EGRAPHIQUE key);
            bool onEvent(EGRAPHIQUE event);

            business::BusinessInterface* getBusiness();
            IGraphiqueEngine* setBusiness(business::BusinessInterface *business);
            IView* getView();
            IGraphiqueEngine* setView(IView *view);
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
        while(this->isActive()) {
            if (this->view) {
                EGRAPHIQUE event = this->view->run();
                this->onEvent(event);
            } else {
                std::cout << "Erreur View absente" << std::endl;
                int choice;
                std::cout << "iciEEE" << std::endl;
                std::cin >> choice;
            }
        }
        return true;
    }

    bool GraphiqueEngine::exit()
    {
        if (this->view) {
            this->view->exit();
        }
        return true;
    }

    bool GraphiqueEngine::drop()
    {
        if (this->view) {
            this->view->drop();
        }
        return true;
    }

    business::BusinessInterface* GraphiqueEngine::getBusiness()
    {
        return this->business;
    }

    IGraphiqueEngine* GraphiqueEngine::setBusiness(business::BusinessInterface *business)
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

    void GraphiqueEngine::execute(EGRAPHIQUE key) {
        IGraphiqueAction *k = this->keyMap->get(key);
        if (k) {
            k->execute(this);
        } else {
            std::cout << GraphiqueInfoNames[key] << " non trouvé " << this->keyMap->getSize() << std::endl;
        }
                int choice;
                std::cout << "iciEEE" << std::endl;
                std::cin >> choice;
    }

    bool GraphiqueEngine::onEvent(EGRAPHIQUE event) {
        this->execute(event);
        return true;
    }

    bool GraphiqueEngine::isActive() {
        return this->active;
    }

    bool GraphiqueEngine::setActive(bool active) {
        return this->active = active;
    }
}
#endif // GRAPHIQUEENGINE_H
