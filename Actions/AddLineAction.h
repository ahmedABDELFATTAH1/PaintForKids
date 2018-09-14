#pragma once
#ifndef ADD_Line_ACTION_H
#define ADD_Line_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddLineAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddLineAction::AddLineAction(ApplicationManager * pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	void AddLineAction::Execute();

};

#endif