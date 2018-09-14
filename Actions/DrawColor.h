#pragma once
#include "Action.h"
class DrawColor :public Action
{
private:
	Point P1;
	color ca;
	ActionType a;
public:
	DrawColor::DrawColor(ApplicationManager * pApp);
	void DrawColor::ReadActionParameters();
	void DrawColor::Execute();
};
