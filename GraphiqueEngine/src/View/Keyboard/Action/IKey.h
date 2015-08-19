#ifndef IACTIONKEY_H
#define IACTIONKEY_H

#include "EKey.h"
#include "../../IView.h"
#include "../../../Business/Event/EActionEvent.h"

namespace graphique
{
    class IKey
    {
        protected:
            EKEY key;
            bool vdown;

        public:
            IKey(){
                this->vdown = false;
            };
            virtual ~IKey(){};

            void down(){
                this->vdown = true;
            }

            void up() {
                this->vdown = false;
            }

            bool isDown(){
                return this->vdown;
            }

            virtual int execute(IView *view){
                return -1;
            };

            virtual int executePressed(IView *view){
                return -1;
            };
    };
} // graphique

#endif
