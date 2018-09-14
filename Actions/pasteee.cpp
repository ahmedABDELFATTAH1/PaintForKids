#include "..\ApplicationManager.h"
#include "pasteee.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

pasteee::pasteee(ApplicationManager * pApp) :Action(pApp)
{
}


void pasteee::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->issellected())
	{
		pOut->PrintMessage("select the place to past in ");
		pIn->GetPointClicked(P1.x, P1.y);
		
	}
	else
	pOut->PrintMessage("please select a figure first XD ");
}


void pasteee::Execute()
{
	ReadActionParameters();
	pManager->pastethefigure(P1.x, P1.y);
	
	
}