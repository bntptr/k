#ifndef VIEW_SKY_CHANGESKY_H
#define VIEW_SKY_CHANGESKY_H

#include "IAction.h"

namespace graphique
{
    namespace sky
    {
        class ChangeSky : public IAction
        {
            public:
                ChangeSky(){};
                virtual ~ChangeSky(){};

                int execute(ISkyView *sky) {
                    ISceneNode* Skybox;
                    ISceneNode* Skydome;
                    bool showBox;
                    Skybox = sky->getSkyBox();
                    Skydome = sky->getSkyDome();
                    // toggle skies
                    showBox =! sky->getShowBox();
                    sky->setShowBox(showBox);
                    Skybox->setVisible(showBox);
                    Skydome->setVisible(!showBox);
                }
        };
    }
} // graphique

#endif


