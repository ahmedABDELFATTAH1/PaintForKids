#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();    //return enum user action

		//Exexute the action
		AppManager.ExecuteAction(ActType);  //creat object of the action

		//Update the interface
		AppManager.UpdateInterface();	// this draw the figure list on the interface of the program

	}while(ActType != EXIT);
	

	
	return 0;
}

