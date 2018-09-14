#include "..\ApplicationManager.h"
#include "changetoplay.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
changetoplay::changetoplay(ApplicationManager * pApp) :Action(pApp)
{}

void changetoplay::ReadActionParameters() {

	

}
void changetoplay::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
	pOut->Cleartoolbar();
	pOut->CreatePlayToolBar();
	



}