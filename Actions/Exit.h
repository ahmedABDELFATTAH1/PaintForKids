#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include <cstring>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class Exit :public Action
{
public :
	Exit(ApplicationManager *pApp);
	~Exit();
	void ReadActionParameters();
	void Execute();
	
};

