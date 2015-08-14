#ifndef VIEWEVENTRECEIVER_H
#define VIEWEVENTRECEIVER_H

#include <irrlicht.h>
#include <iostream>
#include "Action/KeyQ.h"
#include "Action/KeyS.h"
#include "Action/KeyD.h"
#include "Action/KeyF.h"
#include "Action/KeyW.h"

using namespace irr;

namespace graphique
{
    class ViewEventReceiver : public IEventReceiver
    {
        private:
            IView* view;

        public:
            ViewEventReceiver(IView *view)
            {
                this->setView(view);
            }

            /*/// methode Sourie2D
            bool OnEventSourie2D(const SEvent& event)
            {
                 if(sourie != NULL)
                          return sourie->OnEventSourie2D(event);
                  return false;
             }

             /// methode Sourie3D
             bool OnEventSourie3D(const SEvent& event)
            {
                  return false;
             }

             /// methode Clavier
             bool OnEventClavier(const SEvent& event)
            {
                  if(clav != NULL)
                          return clav->OnEventClavier(event);
                  return false;

             }

             /// methode GUI
             bool OnEventGUI(const SEvent& event)
            {
                  if(env != NULL)
                         return env->OnEventGUI(event);

                  return false;
             }*/

            bool OnEvent(const SEvent& event)
            {
                /// Sourie  (irr::gui::ICursorControl Class Reference)
                if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
                {
                    //OnEventSourie2D(event);
                }

                /// Clavier
                if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown)
                {
                    IKey *key;
                    switch (event.KeyInput.Key)
                    {
                    case irr::KEY_KEY_Q:
                        key = new KeyQ();
                        key->execute(this->view);
                        return true;
                    case irr::KEY_KEY_F:
                        key = new KeyF();
                        key->execute(this->view);
                        return true;
                    case irr::KEY_KEY_D:
                        key = new KeyD();
                        key->execute(this->view);
                        return true;
                    case irr::KEY_KEY_S:
                        key = new KeyS();
                        key->execute(this->view);
                        return true;

                    case irr::KEY_KEY_W:
                        key = new KeyW();
                        key->execute(this->view);
                        return true;
                    case irr::KEY_KEY_X:
                        //this->actionKeyService->execute(EACTIONKEY_X);
                        return true;
                    case irr::KEY_KEY_C:
                        return true;
                    case irr::KEY_KEY_V:
                        return true;
                    default:
                        break;
                    }
                }

                /// GUI Environnement
                if (event.EventType == irr::EET_GUI_EVENT)
                {
                    //OnEventGUI(event);
                }

                return false;
            }

            ViewEventReceiver* setView(IView *view) {
                this->view = view;
                return this;
            }
    };
}

#endif

