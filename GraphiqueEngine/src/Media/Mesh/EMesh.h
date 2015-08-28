#ifndef EMESH_H_
#define EMESH_H_

/**
 * Devrait être dans BUSINESS
 */
//! Enumeration de tous les types de Texture
enum EMESH
{

	EMESH_NINJA=0,
	EMESH_FAERIE,
	EMESH_SYDNEY,
	EMESH_NAIN,
	EMESH_GUN,
	EMESH_PENGUIN,
	EMESH_TERRAIN_DEFAULT,

};

/**
 * Devrait être dans VIEW
 */
const char* const MESHInfoNames[] =
{
         "ninja.b3d",
         "faerie.md2",
         "sydney.md2",
         "dwarf.x",
         "gun.md2",
         "Mesh/penguin.mesh",
         "terrain-heightmap-plat-bas.bmp",
         0
};
#endif /* EMESH_H_ */

