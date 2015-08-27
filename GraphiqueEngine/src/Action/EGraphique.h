#ifndef EGRAPHIQUE_H_
#define EGRAPHIQUE_H_

//! Enumeration de tous les id des actions de Graphique engine
enum EGRAPHIQUE
{
    //! Action
	EGRAPHIQUE_VIEW_LOADING=0,
	EGRAPHIQUE_VIEW_2D,
	EGRAPHIQUE_VIEW_3D,
	EGRAPHIQUE_VIEW_MENU,
	EGRAPHIQUE_VIEW_EDITOR,
	EGRAPHIQUE_CLOSE,

	//! Error
	EGRAPHIQUE_ERROR_DRIVER,
};

const char* const GraphiqueInfoNames[] =
{
         "loading...",
         "view 2d",
         "view 3d",
         "View menu",
         "view Editor",
         "close",
         "Erreur driver (could not create selected driver)"
         "",
         0
};
#endif /* EGRAPHIQUE_H_ */



