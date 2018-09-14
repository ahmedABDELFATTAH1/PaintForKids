#pragma once

#include "Action.h"

//Add Rectangle Action class
class pasteee : public Action
{
private:
	Point P1;

public:
	pasteee(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


};

