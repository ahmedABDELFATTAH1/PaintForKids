#ifndef PICK_TYPE_ACTION
#define PICK_TYPE_ACTION

#include "Action.h"


class PickTypeAction : public Action
{
private:
	Point p;
	int countright;
	int countwrong;
	

public:
	PickTypeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif