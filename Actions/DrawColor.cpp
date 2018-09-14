#include "..\ApplicationManager.h"
#include "DrawColor.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
DrawColor::DrawColor(ApplicationManager * pApp) :Action(pApp)
{}
void DrawColor::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please select The Color you want to use it as Draw color ");
	ActionType a;
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
		pOut->PrintMessage("Collor BLACK");
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
void DrawColor::Execute() {
	ReadActionParameters();
	if (pManager->isis()) {
		pManager->Drawselected(ca);
	}
	else {
		
		UI.DrawColor = ca;
		UI.FILLED = false;
	}

}
	
	

	
	
	
