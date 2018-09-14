#pragma once
#include "Action.h"
class Resizeaction :public Action
{
private:
	ActionType act;

public:
	Resizeaction::Resizeaction(ApplicationManager * pApp);
	void Resizeaction::ReadActionParameters();
	void Resizeaction::Execute();





};


