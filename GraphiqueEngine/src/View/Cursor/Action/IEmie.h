#ifndef IEMIE_H
#define IEMIE_H

#include "../../IView.h"
#include "../../../Business/Event/EActionEvent.h"

namespace graphique
{
    class IEmie
    {
        public:
            IEmie(){};
            virtual ~IEmie(){};

            virtual int execute(IView *view){
                return -1;
            };;

            virtual int executePressed(IView *view){
                return -1;
            };
    };
} // graphique

#endif
