#ifndef IACTION_SOUND_H
#define IACTION_SOUND_H

#include <irrKlang.h>
#include "ESound.h"

namespace graphique
{
    class ISound
    {

        public:
            ISound(){};
            virtual ~ISound(){};

            virtual int play(){
                return -1;
            };
    };
} // graphique

#endif
