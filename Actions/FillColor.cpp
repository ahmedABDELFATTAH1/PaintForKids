#include "..\ApplicationManager.h"
#include "FillColor.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
FillColor::FillColor(ApplicationManager * pApp) :Action(pApp)
{}
void FillColor::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please select The Color you want to use it as Fill color ");
	
	a = (pManager->GetUserAction());
	switch (a)
	{
	case 4:
		ca = WWHITE;
		pOut->PrintMessage("COLOR WHITE");
		break;
	case 5:
		ca = GGREEN;
		pOut->PrintMessage("Collor GREEN");
		break;
	case 6:
		ca = RRED;
		pOut->PrintMessage("Collor RED");
		break;
	case 7:
		pOut->PrintMessage("Collor  BLACK");
		ca = BBLACK;
		break;
	case 8:
		ca = BBLUE;
		pOut->PrintMessage("Collor BLUE");
		break;
	default:
		break;
	}

	
}
void FillColor::Execute() {
	ReadActionParameters();
	if (pManager->isis()) {
		pManager->Fillselected(ca);
	}
	else {
		UI.FillColor = ca;
		UI.FILLED = true;
	}
	
	}