#ifndef VIEW_KEYBOARD_SERVICE_H
#define VIEW_KEYBOARD_SERVICE_H

#include "Action/Actions.h"
#include "IKeyboardService.h"
#include "KeyboardFactory.h"

namespace graphique
{
    class KeyboardService : public IKeyboardService
    {
        protected:
            IKeyboardService* thisInstance;
            IKeyboard *keyboard;

        public:
            KeyboardService(){
                this->thisInstance = this;
            };
            KeyboardService(IView *view){
                this->thisInstance = this;
                this->keyboard = KeyboardFactory::createEntity(view);
            };
            ~KeyboardService(){};

            IKeyboard* down(irr::EKEY_CODE key) {
                return this->keyboard->down(key);
            }

            IKeyboard* up(irr::EKEY_CODE key) {
                return this->keyboard->up(key);
            }

            bool isDown(irr::EKEY_CODE key) {
                return this->keyboard->isDown(key);
            }

            IKeyboard* execute(irr::EKEY_CODE key) {
                return this->keyboard->execute(key);
            }

            IKeyboard* executePressed(irr::EKEY_CODE key) {
                return this->keyboard->executePressed(key);
            }

            // Les autres ci dessus inutil chez le service?
            bool onEvent(const irr::SEvent& event) {
                return this->keyboard->onEvent(event);
            }

            bool onEventPressed(const irr::SEvent& event) {
                return this->keyboard->onEventPressed(event);
            }
    };
} // business

#endif




