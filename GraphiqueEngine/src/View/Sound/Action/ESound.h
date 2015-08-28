#ifndef ESOUND_H_
#define ESOUND_H_

//! Enumeration de tous les id de Sound
enum ESOUND
{
    /// music de fond
	ESOUND_LOADING=0,

    /// bruitage
	ESOUND_IMPACT,

    /// playlist parole
	ESOUND_PAROL_HELLO,
};

const char* const KeyInfoNames[] =
{
         "music loading...",
         "bruitage impact",
         "parole hello",
         0
};
#endif /* ESOUND_H_ */


