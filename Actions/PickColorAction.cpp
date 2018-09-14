#include"PickColorAction.h"
#include"..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include <cstdlib>
int rand();

PickColorAction :: PickColorAction (ApplicationManager *pApp) : Action (pApp)
{
	countright=0;
	countwrong=0;
}
void PickColorAction :: ReadActionParameters()
{}

void PickColorAction :: Execute()
{
	
	ReadActionParameters();
	Point p;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// call function btn2l el original array ll copy array 3shan a delete fiha zy ma ana 3aiza 
	CFigure** Copy= new CFigure* [200];
	 pManager->CopyArray(Copy);
	pOut-> ClearDrawArea();
	int copycount = pManager->getfigcount();
	//elmfrod a caal function to clear drawing area
	pManager->UpdateCopyInterface(Copy, copycount );

	 int arr[5]; // RED-0 GREEN-1 BLUE-2 BLACK-3 WHITE-4
	 for ( int i=0 ; i<5 ; i++)
	 {
		 arr[i]=0;
	 }
	 pManager->CalcNumOfColors(arr, 5);

	
	 int x;
	 while (x= (rand()%5) +1) 
	 {
		 if ( x==1 && arr[x-1] != 0) pOut ->PrintMessage("click on all figures with fillig color -> RED ");
		 if ( x==2 && arr[x-1] != 0) pOut ->PrintMessage("click on all figures with fillig color -> GREEN ");
		 if ( x==3 && arr[x-1] != 0) pOut ->PrintMessage("click on all figures with fillig color -> BLUE");
		 if ( x==4 && arr[x-1] != 0) pOut ->PrintMessage("click on all figures with fillig color -> BLACK");
		 if ( x==5 && arr[x-1] != 0) pOut ->PrintMessage("click on all figures with fillig color -> WHITE");
		 while (countright < arr[x-1])
				{
					pIn->GetPointClicked( p.x, p.y);
					if (pManager->FigureFillColor(p.x, p.y, Copy, copycount, x))
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