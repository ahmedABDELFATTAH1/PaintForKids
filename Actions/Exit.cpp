#include "Exit.h"
#include"Action.h"


Exit::Exit(ApplicationManager * pApp) :Action(pApp) { ; }

  void Exit::ReadActionParameters() 
 {
	Output* pOut = pManager ->GetOutput();
	Input* pIn = pManager ->GetInput();
}
  void  Exit::Execute()
  {
	  
  }
 


Exit::~Exit()
{
}
