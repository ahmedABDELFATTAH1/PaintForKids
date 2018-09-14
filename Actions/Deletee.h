
#pragma once
#include "Action.h"

//Add Rectangle Action class
class Deletee : public Action
{
private:
	Point P1;

public:
	Deletee(ApplicationManager * pApp);

	void ReadActionParameters();

	void Execute();


};


