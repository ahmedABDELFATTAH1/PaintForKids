#pragma once
#include "Action.h"
class changetoplay :public Action
{
private:
	Point P1;

public:
	changetoplay::changetoplay(ApplicationManager * pApp);
	void changetoplay::ReadActionParameters();
	void changetoplay::Execute();





};

