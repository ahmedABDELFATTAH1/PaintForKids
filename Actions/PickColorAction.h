#ifndef PICK_COLOR_ACTION
#define PICK_COLOR_ACTION
#include"Action.h"


class PickColorAction : public Action
{
	int countright;
	int countwrong;

public:
	PickColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};


#endif