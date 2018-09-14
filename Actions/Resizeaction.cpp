#include "..\ApplicationManager.h"
#include "Resizeaction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Resizeaction::Resizeaction(ApplicationManager * pApp) :Action(pApp)
{}

void Resizeaction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->isis())
	{
		pOut->PrintMessage("please select how you want to Resize the selected figure");
		act=pIn->GetUserAction();
	}
	else {

		pOut->PrintMessage("You should select a figure first XD");
	}



}
void Resizeaction::Execute()
{
	ReadActionParameters();
	if (pManager->isis())
	pManager->changesize(act);
	
	
	}