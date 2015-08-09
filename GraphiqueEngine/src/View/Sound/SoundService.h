#ifndef SOUNDSERVICE_H
#define SOUNDSERVICE_H

namespace graphique
{
    class SoundService
    {
        public:
            SoundService(){};
            ~SoundService(){};

            SoundService* run(){
                /*irr::audio::ISoundEngine* soundEngine = irr::audio::createIrrKlangDevice();
                IrrlichtDevice* device = createDevice(video::EDT_OPENGL, core::dimension2d<s32>(640, 480), 16, false);
                scene::ISceneManager* smgr = device->getSceneManager();

                // .. other code here

                CIrrKlangSceneNode* soundNode =
                    new CIrrKlangSceneNode(soundEngine, smgr->getRootSceneNode(), smgr, 666);

                soundNode->setSoundFileName("yourfile.wav");
                soundNode->setMinMaxSoundDistance(30.0f); // influences the distance where the sound can be heard
                soundNode->setRandomMode(1000, 5000); // plays sound multiple times with random interval

                // other modes would be:
                // soundNode->setLoopingStreamMode()
                // or
                // soundNode->setPlayOnceMode();

                soundNode->drop();*/
                return this;
            }
    };
} // graphique

#endif

