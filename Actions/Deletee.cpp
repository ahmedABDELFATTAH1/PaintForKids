#include "..\ApplicationManager.h"
#include "Deletee.h"
#include "AddSelectAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Deletee::Deletee(ApplicationManager * pApp) :Action(pApp)
{
}


void Deletee::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->issellected())
		pOut->PrintMessage("The sellected figus is deleted ");
	else
		pOut->PrintMessage("select the figure first ");
}


void Deletee::Execute()
{
	ReadActionParameters();
	if (pManager->issellected())
		pManager->del();
}