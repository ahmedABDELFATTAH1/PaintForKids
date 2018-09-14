#include "..\ApplicationManager.h"
#include "cutt.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

cutt::cutt(ApplicationManager * pApp) :Action(pApp)
{


}


void cutt::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->issellected())
		pOut->PrintMessage("The sellected figus is cut ");
	else
		pOut->PrintMessage("select the figer first ");


}


void cutt::Execute()
{
	ReadActionParameters();
	if (pManager->issellected())
	{
		CFigure * temp = pManager->getClipboard();
		if(temp!=NULL)
			delete temp;
		pManager->setclipboard();
		pManager->del();
	}

}