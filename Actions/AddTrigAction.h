
#ifndef ADD_TRIG_ACTION_H
#define ADD_TRIG_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddTrigAction : public Action
{
private:
	Point P1, P2, P3; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddTrigAction::AddTrigAction(ApplicationManager * pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif