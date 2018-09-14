#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first corner");
	
	pOut->PrintMessage("New Circle: Click at first cornersdsdg");
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	radius = sqrt(pow(P2.x - P1.x ,2.0) - pow(P2.y - P1.y,2.0));
	pOut->PrintMessage("New Circle: Click at second corner");
	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.FILLED;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle *R = new CCircle(P1, P2,radius,RectGfxInfo);
    
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
