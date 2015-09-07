#ifndef VIEW_MOUSE_BUTTON_H
#define VIEW_MOUSE_BUTTON_H

#include "IMouseButton.h"

namespace graphique
{
    class MouseButton : public IMouseButton
    {
        protected:
            bool vdown;

        public:
            MouseButton(){
                this->vdown = false;
            };
            virtual ~MouseButton(){};

            void down(){
                this->vdown = true;
            }

            void up() {
                this->vdown = false;
            }

            bool isDown(){
                return this->vdown;
            }
    };
} // graphique

#endif

