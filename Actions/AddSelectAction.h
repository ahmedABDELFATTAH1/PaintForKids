#pragma once
#include "Action.h"
class AddSelectAction :public Action
{
private:
	Point P1;

public:
	AddSelectAction::AddSelectAction(ApplicationManager * pApp);
	void AddSelectAction::ReadActionParameters();
	void AddSelectAction::Execute();
	




};

