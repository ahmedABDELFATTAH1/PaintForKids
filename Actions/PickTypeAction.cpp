

#include "PickTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include <cstdlib>
int rand();

#include <iostream>
using namespace std;

PickTypeAction :: PickTypeAction (ApplicationManager * pApp) : Action ( pApp )
{

	countright=0;
	countwrong=0;

}



void PickTypeAction :: ReadActionParameters()
{

}


void PickTypeAction:: Execute() 
{
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// call function btn2l el original array ll copy array 3shan a delete fiha zy ma ana 3aiza 
	
	CFigure** Copy= new CFigure* [200];
	
	pManager->CopyArray(Copy);
	int copycount = pManager->getfigcount();
	//elmfrod a caal function to clear drawing area
	pOut-> ClearDrawArea();
	pManager->UpdateCopyInterface(Copy, copycount );

	
	 int arr[4];
	 for ( int i=0 ; i<4 ; i++)
	 {
		 arr[i]=0;
	 }
	 pManager-> CalcNumOfShapes( arr , 4);

	

	 int x;
	 while (x= (rand()%4) +1) 
	 {
		 if ( x==1 && arr[x-1] != 0) pOut ->PrintMessage("click on all rectangles ");
		 if ( x==2 && arr[x-1] != 0) pOut ->PrintMessage("click on all circles ");
		 if ( x==3 && arr[x-1] != 0) pOut ->PrintMessage("click on all triangles ");
		 if ( x==4 && arr[x-1] != 0) pOut ->PrintMessage("click on all lines ");

		 while (countright < arr[x-1])
				{
					pIn->GetPointClicked( p.x, p.y);
					if (pManager->pointInFigure(p.x, p.y, Copy, copycount, x))
						countright++;
					else countwrong++;

					auto str1 = std::to_string(countright);
					auto str2 = std::to_string(countwrong);
					pOut->ClearStatusBar();
					pOut->PrintMessage("right counts  = "+str1+" wrong counts = "+str2);
				}

		 if (countright!= 0 || countwrong!= 0)
		      {
				pOut->ClearStatusBar();
				pOut->PrintMessage("WELL DONE ! Choose another game...");
				break;
		      }
	 }

}

