#include "..\ApplicationManager.h"
#include "AddSelectAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddSelectAction::AddSelectAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddSelectAction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please select The figure you want ");

	pIn->GetPointClicked(P1.x, P1.y);


}
void AddSelectAction::Execute()
{
	ReadActionParameters();
	CFigure* s = pManager->GetFigure(P1.x, P1.y);
    pManager->printinfo(s);
	
	
	
}