#include "..\ApplicationManager.h"
#include "copyy.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

copyy::copyy(ApplicationManager * pApp) :Action(pApp)
{
}


void copyy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->issellected())
		pOut->PrintMessage("The sellected figus is copied ");
	else
		pOut->PrintMessage("select the figer first ");


}


void copyy::Execute()
{
	ReadActionParameters();
	if (pManager->issellected())
	{
		CFigure * temp = pManager->getClipboard();
		if(temp!=NULL)
			delete temp;
		pManager->setclipboard();
		pManager->Nselect();
	}
}