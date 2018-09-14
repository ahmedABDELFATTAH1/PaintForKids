#include"Action.h"
#include "loadd.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"


loadd::loadd(ApplicationManager *pApp) :Action(pApp)
{
}

void loadd::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter the file name you want to load ");
	file = pIn->GetSrting(pOut);
}
void  loadd::Execute() {
	ReadActionParameters();
	int id;
	string drawcolor ="a";//the drawing color of the last figure
	string fillcolor="b";//the fill color of the last figure
	string type;
	types t = types::LINEa;
	int FigCount=0;
	pManager->clear();
	ifstream InFile(file);
	InFile >> drawcolor >> fillcolor >> FigCount;
	for (int i = 0; i < FigCount; i++) {
		InFile >> type >> id;
		if (type == "CIRCLE")
			t = CIRCa;
		if (type == "LINE")
			t = LINEa;
		if (type == "RECTANGLE")
			t = RECTa;
		if (type == "TRIANGLE")
			t = TRIGa;

		CFigure * p;
		switch (t)
		{
			case CIRCa:
			{
				p = new CCircle();
				break;
			}

			case LINEa:
			{
				p = new CLine();
				break;

				break;
			}

			case RECTa:
			{
				p = new CRectangle();
				break;
			}

			case TRIGa:
			{
				p = new CTriangle();
				break;
			}

		}
		p->Load(InFile);
		pManager->AddFigure(p);
	}

}


loadd::~loadd()
{
}
