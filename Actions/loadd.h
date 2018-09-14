#pragma once
#include "Action.h"
#include<fstream>
#include"savee.h"
#include "..\ApplicationManager.h"


class loadd :public Action
{
	
	string file;

public:
	loadd(ApplicationManager *pApp);
	~loadd();
	void ReadActionParameters();
	void Execute();

};

