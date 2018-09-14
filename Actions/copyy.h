#pragma once

#include "Action.h"
//2 function aded in cfigur an variable is aded in app manager called gfxinfo we 2 function kaman we files of copy .h we .cpp

class copyy : public Action
{
private:

public:
	copyy(ApplicationManager * pApp);

	virtual void ReadActionParameters();
	virtual void Execute();


};

