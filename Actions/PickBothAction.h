#ifndef PICK_BOTH_ACTION
#define PICK_BOTH_ACTION
#include"Action.h"


class PickBothAction :public Action
{

	private:
	int countright;
	int countwrong;
	

public:
	PickBothAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif

