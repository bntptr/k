#ifndef ETEXTURE_H_
#define ETEXTURE_H_

/**
 * Devrait être dans BUSINESS
 */
//! Enumeration de tous les types de Texture
enum ETEXTURE
{

	ETEXTURE_NINJA=0,
	ETEXTURE_NINJA_GREEN,
	ETEXTURE_NINJA_RED,
	ETEXTURE_NINJA_BLUE,
	ETEXTURE_FAERIE,
	ETEXTURE_SYDNEY,
	ETEXTURE_NAIN,
	ETEXTURE_GUN,
	ETEXTURE_PENGUIN,

};

/**
 * Devrait être dans VIEW
 */
const char* const TEXTUREInfoNames[] =
{
         "nskinrd2.jpg",
         "nskingr.jpg",
         "nskinrd.jpg",
         "nskinbl.jpg",
         "faerie.bmp",
         "sydney.bmp",
         "",
         "gun.jpg",
         "Texture/penguin.jpg",
         0
};
#endif /* ETEXTURE_H_ */

