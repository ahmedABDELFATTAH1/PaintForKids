#include "..\ApplicationManager.h"
#include "sendfrontt.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
////one created  function in appmanager calledsendback
sendfrontt::sendfrontt(ApplicationManager * pApp):Action(pApp)
{
}
void sendfrontt::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->issellected())
		pOut->PrintMessage("The selected figure is sent to front ");
	else
		pOut->PrintMessage("select the figer first ");
	
	

}
	
	
void sendfrontt:: Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->sendfront();
	pOut->ClearStatusBar();
}
