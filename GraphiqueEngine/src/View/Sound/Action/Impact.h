#ifndef IACTION_SOUND_IMPACT_H
#define IACTION_SOUND_IMPACT_H

#include "ISound.h"

namespace graphique
{
    class Impact : public ISound
    {
        public:
            Impact(){};
            virtual ~Impact(){};

            int play() {
                using namespace irrklang;
            	// start the sound engine with default parameters
                irrklang::ISoundEngine* device = createIrrKlangDevice();

                if (!device)
                    return -1; // error starting up the engine

                // play some sound stream, looped
                device->play2D("impact.wav", true);

                device->drop(); // delete engine
                return 0;
            }
    };
} // graphique

#endif


