#pragma once
#include "Action.h"
#include<fstream>
#include<Cstring>
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class savee : public Action
{
	//ApplicationManager*app;
	string filename;
	~savee();
	void ReadActionParameters();
	void Execute();
public:
	savee(ApplicationManager * pApp);

	string getfile();

};

