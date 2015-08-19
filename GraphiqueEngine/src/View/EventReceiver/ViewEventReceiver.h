/**
 * source file:///home/ubuntu/Workspaces/Sources/irrlicht-1.6.1/doc/html/namespaceirr.html#c9eed96e06e85ce3c86fcbbbe9e48a0c
 */
#ifndef VIEWEVENTRECEIVER_H
#define VIEWEVENTRECEIVER_H

#include <irrlicht.h>
#include <iostream>
#include "../Keyboard/Keyboard.h"
#include "../Cursor/CursorEntity.h"
#include "../Keyboard/Action/Actions.h"
#include "../Cursor/Action/Actions.h"

using namespace irr;

namespace graphique
{
    class ViewEventReceiver : public IEventReceiver
    {
        private:
            IView* view;
            IKeyboard *keyboard;
            ICursorEntity *cursor;
            IEnvironnement *env;

        public:
            ViewEventReceiver(IView *view)
            {
                this->view = view;
                this->keyboard = KeyboardFactory::createEntity();
                this->cursor = CursorFactory::createEntity();
                this->env = view->getEnvironnement();
            }

            /// methode Sourie 2D & 3D
            bool OnEventSourie(const SEvent& event)
            {
                 if(this->cursor != NULL)
                          return this->cursor->onEvent(event);
                  return false;
             }

             /// methode Clavier
             bool OnEventClavier(const SEvent& event)
            {
                  if(this->keyboard != NULL) {
                    if (event.KeyInput.PressedDown) {
                        return this->keyboard->onEventPressed(event);
                    } else {
                        return this->keyboard->onEvent(event);
                    }

                  }
                  return false;

             }

             /// methode GUI
             bool OnEventGUI(const SEvent& event)
            {
                  if(this->env != NULL)
                         return this->env->onEvent(event);

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

