#include "..\ApplicationManager.h"
#include "sendback.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
////one created  function in appmanager calledsendback
sendback::sendback(ApplicationManager * pApp):Action(pApp)
{
}
void sendback::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

    if(pManager->issellected())
		pOut->PrintMessage("The selected figure is sent to back ");
	else
		pOut->PrintMessage("select the figer first ");	

}
	
	
void sendback:: Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->sentback();
	pOut->ClearStatusBar();
}
