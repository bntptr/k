#ifndef EVIEW_H_
#define EVIEW_H_

//! Enumeration de tous les id des actions de View déclanché par le joueur
enum EVIEW
{
    /// ligne 1
	EVIEW_CLOSE_WINDOWS=0,
	EVIEW_MODE_2D,
	EVIEW_MODE_FPS,
	EVIEW_MODE_RTS,
	EVIEW_MODE_RPG,
	EVIEW_MODE_EDITOR,
};

const char* const ViewInfoNames[] =
{
         "close windows",
         "mode 2d",
         "mode FPS",
         "mode RTS",
         "mode RPG",
         "mode Editor",
         "",
         0
};
#endif /* EVIEW_H_ */



