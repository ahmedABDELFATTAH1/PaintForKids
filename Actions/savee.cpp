#include"savee.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<cstring>
#include<iostream>

using namespace std;
savee::savee(ApplicationManager * pApp) :Action(pApp) { ; }

savee::~savee() { ; }

string savee::getfile() {
	return filename;
}
void savee::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter the file name you want to save within ");
	filename = pIn->GetSrting(pOut);
}

void savee::Execute() {

	ReadActionParameters();

	ofstream OutFile(filename);
	pManager->saveall(OutFile);
	OutFile.close();


}
