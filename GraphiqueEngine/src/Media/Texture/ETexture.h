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
	ETEXTURE_TERRAIN_DEFAULT,

	//! Texture 2d .png
	ETEXTURE_TERRAIN_2D_PRAIRIE,

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
         "terrain-texture-plat-riviere.jpg",
         0
};

/**
 * Devrait être dans VIEW
 */
const char* const TEXTURE2DInfoNames[] =
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
         "Terrain/Texture2d/prairie.png",
         0
};

#endif /* ETEXTURE_H_ */

