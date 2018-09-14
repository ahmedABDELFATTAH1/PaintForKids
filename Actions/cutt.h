#pragma once


#include "Action.h"

//Add Rectangle Action class
class cutt : public Action
{
private:
	Point P1;

public:
	cutt(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


};

