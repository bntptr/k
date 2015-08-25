/**
 * source file:///home/ubuntu/Workspaces/Sources/irrlicht-1.6.1/doc/html/namespaceirr.html#c9eed96e06e85ce3c86fcbbbe9e48a0c
 */
#ifndef VIEWEVENTRECEIVER_H
#define VIEWEVENTRECEIVER_H

#include <irrlicht.h>
#include <iostream>
#include "../Keyboard/KeyboardServiceFactory.h"
#include "../Cursor/CursorFactory.h"
#include "../Keyboard/Action/Actions.h"
#include "../Cursor/Action/Actions.h"

using namespace irr;

namespace graphique
{
    class ViewEventReceiver : public IEventReceiver
    {
        private:
            IView* view;
            IKeyboardService *keyboard;
            ICursorEntity *cursor;
            IEnvironnementService *env;

        public:
            ViewEventReceiver(IView *view)
            {
                this->view = view;
                this->keyboard = view->getKeyboardService();
                this->cursor = view->getCursor();
                this->env = view->getEnvironnementService();
            }

            /// methode Sourie 2D & 3D
            bool OnEventSourie(const SEvent& event)
            {
                 if(this->cursor != NULL)
                          return this->cursor->oneEvent(event);
                  return false;
             }

             /// methode Clavier
             bool OnEventClavier(const SEvent& event)
            {
                  if(this->keyboard != NULL) {
                    if (event.KeyInput.PressedDown) {
                        return this->keyboard->oneEventPressed(event);
                    } else {
                        return this->keyboard->oneEvent(event);
                    }

                  }
                  return false;

             }

             /// methode GUI
             bool OnEventGUI(const SEvent& event)
            {
                  if(this->env != NULL)
                         return this->env->oneEvent(event);

                  return false;
             }

            bool OnEvent(const SEvent& event)
            {
                /// Sourie  (irr::gui::ICursorControl Class Reference)
                if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
                {
                    OnEventSourie(event);
                }

                /// Clavier
                if (event.EventType == irr::EET_KEY_INPUT_EVENT)
                {
                    OnEventClavier(event);
                }

                /// GUI Environnement
                if (event.EventType == irr::EET_GUI_EVENT)
                {
                    OnEventGUI(event);
                }

                /// Joystick
                if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT)
                {
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

