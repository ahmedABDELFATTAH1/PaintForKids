#pragma once
#include "Action.h"
class FillColor :public Action
{
private:
	Point P1;
	color ca;
	ActionType a;
public:
	FillColor::FillColor(ApplicationManager * pApp);
	void FillColor::ReadActionParameters();
	void FillColor::Execute();
};
