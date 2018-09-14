#pragma once

#include "Action.h"
class sendfrontt : public Action
{
	public:
	sendfrontt (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;






};