#ifndef EACTION_EVENT_VIEW_H_
#define EACTION_EVENT_VIEW_H_

//! Enumeration de tous les types de ACTION EVENT
enum EACTIONEVENT
{

	EACTIONEVENT_DEFAULT=0,
	EACTIONEVENT_DEPLACE_X,
	EACTIONEVENT_DEPLACE_Y,
	EACTIONEVENT_DEPLACE_Z,
	EACTIONEVENT_DEPLACE_SAUT,
	EACTIONEVENT_POSTURE_ALLONGE,
	EACTIONEVENT_POSTURE_ACCROUPI,
	EACTIONEVENT_POSTURE_DEBOUT,

	EACTIONEVENT_CHANGE_SKY,
	EACTIONEVENT_TERRAIN_MAP_DETAIL, // D
	EACTIONEVENT_TERRAIN_MAP_TRIANGLE, // Q
	EACTIONEVENT_TERRAIN_MAP_POINT, // F

};
const char* const ACTIONEVENTInfoNames[] =
{
         "Action default",
         "Action deplace X",
         "Action deplace Y",
         "Action deplace Z",
         "Action deplace saut",
         "Action posture allonge",
         "Action posture accroupi",
         "Action posture denout",

         "Action change Sky",
         "Action change detail",
         "Action change triangle",
         "Action change point",
};
#endif /* EACTION_EVENT_VIEW_H_ */

