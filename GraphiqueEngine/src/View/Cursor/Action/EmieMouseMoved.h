#ifndef EMIE_MOUSE_MOVED_H
#define EMIE_MOUSE_MOVED_H

#include "IEmie.h"

namespace graphique
{
    class EmieMouseMoved : public IEmie
    {
        public:
            EmieMouseMoved(){};
            virtual ~EmieMouseMoved(){};

            int execute(IView *view) {
                        /*MouseState.Position.X = event.MouseInput.X;
                        MouseState.Position.Y = event.MouseInput.Y;
                        cursor->setX(event.MouseInput.X); //si marche pas utiliser "core::position2di Position;" dans MyCursor
                        cursor->setY(event.MouseInput.Y);
                        cursor->run();*/
                return 0;
            }
    };
} // graphique

#endif


