#include "ToDrawAction.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

ToDrawAction :: ToDrawAction ( ApplicationManager * pApp) : Action(pApp)
{
}
void ToDrawAction :: ReadActionParameters()
{
}
void ToDrawAction :: Execute() 
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	
	pOut->ClearDrawArea();
	pOut->Cleartoolbar();
	pOut->CreateDrawToolBar();
	pManager->UpdateInterface();
	
}