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

	//! Texture Terrain
	ETEXTURE_TERRAIN_DEFAULT,

	//! Texture Sky
	ETEXTURE_SKY_DOME_DEFAULT,
	ETEXTURE_SKY_BOX_DEFAULT_UP,
	ETEXTURE_SKY_BOX_DEFAULT_DN,
	ETEXTURE_SKY_BOX_DEFAULT_LF,
	ETEXTURE_SKY_BOX_DEFAULT_RT,
	ETEXTURE_SKY_BOX_DEFAULT_FT,
	ETEXTURE_SKY_BOX_DEFAULT_BK,

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
    "Sky/Dome/skydome.jpg",
    "Sky/Box/irrlicht2_up.jpg",
    "Sky/Box/irrlicht2_dn.jpg",
    "Sky/Box/irrlicht2_lf.jpg",
    "Sky/Box/irrlicht2_rt.jpg",
    "Sky/Box/irrlicht2_ft.jpg",
    "Sky/Box/irrlicht2_bk.jpg",
     0
};

/**
 * Devrait être dans VIEW
 */
const char* const TEXTURE2DInfoNames[] =
{
    "Texture/Texture2d/2ddemo.png",
    "Texture/Texture2d/2ddemo.png",
    "Texture/Texture2d/2ddemo.png",
    "Texture/Texture2d/2ddemo.png",
    "Texture/Texture2d/2ddemo.png",
    "Texture/Texture2d/2ddemo.png",
    "Texture/Texture2d/2ddemo.png",
    "gun.jpg",
    "Texture/Texture2d/2ddemo.png",
    "Terrain/Texture2d/prairie.png",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    0
};

#endif /* ETEXTURE_H_ */

