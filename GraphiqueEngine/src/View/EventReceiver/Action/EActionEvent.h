#ifndef EACTION_EVENT_VIEW_H_
#define EACTION_EVENT_VIEW_H_

//! Enumeration de tous les types de ACTION EVENT
enum EACTIONEVENT
{

	EACTIONEVENT_DEFAULT=0,
	EACTIONEVENT_DEPLACE_X,
	EACTIONEVENT_DEPLACE_Y,
	EACTIONEVENT_DEPLACE_Z,

};
const char* const ACTIONEVENTInfoNames[] =
{
         "Action default",
         "Action deplace X",
         "Action deplace Y",
         "Action deplace Z",
};
#endif /* EACTION_EVENT_VIEW_H_ */

