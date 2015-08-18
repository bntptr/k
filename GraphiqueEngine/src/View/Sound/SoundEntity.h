#include <iostream>
#include <irrKlang.h>
using namespace irrklang;


		bool run() {
			// start the sound engine with default parameters
			irrklang::ISoundEngine* device = createIrrKlangDevice();

			if (!device)
				return false; // error starting up the engine

			// play some sound stream, looped
			device->play2D("somefile.mp3", true);

			char i = 0;
			std::cin >> i; // wait for user to press some key

			device->drop(); // delete engine
			return false;
		}
