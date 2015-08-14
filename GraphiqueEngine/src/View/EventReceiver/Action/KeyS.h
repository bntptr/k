#ifndef IACTIONKEY_S_H
#define IACTIONKEY_S_H

#include "IKey.h"

namespace graphique
{
    class KeyS : public IKey
    {
        protected:
            irr::scene::ISceneNode* Skybox;
            irr::scene::ISceneNode* Skydome;
            bool showBox;
        public:
            KeyS(){
                this->showBox = true;
            };
            virtual ~KeyS(){};

            int execute(IView *view) {
                this->Skybox = view->getSky()->getSkyBox();
                this->Skydome = view->getSky()->getSkyDome();
                // toggle skies
                this->showBox=!this->showBox;
                this->Skybox->setVisible(showBox);
                this->Skydome->setVisible(!showBox);
            }
    };
} // graphique

#endif


