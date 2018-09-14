#pragma once

#include "Action.h"
class sendback : public Action
{
	public:
	sendback (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;






};