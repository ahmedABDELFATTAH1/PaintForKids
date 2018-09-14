#include "PickBothAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include <cstdlib>
int rand();

PickBothAction:: PickBothAction (ApplicationManager *pApp): Action (pApp)
{
	countright=0;
	countwrong=0;
}
void PickBothAction:: ReadActionParameters()
{
}
void PickBothAction:: Execute() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	Point p;
	
	CFigure** Copy= new CFigure* [200];
	pManager->CopyArray(Copy);
	pOut-> ClearDrawArea();
	int copycount = pManager->getfigcount();
	pManager->UpdateCopyInterface(Copy, copycount );
	
	int arr[3][5];
	 for ( int row =0 ; row<3 ; row ++)  // 0-> rect 1->circle 2->triangle
	 {
		 for (int column =0; column<5 ; column ++)  // 0-red 1-green 2-blue 3-black 4-white
		 {
			 arr[row][column]= 0;
		 }
	 }

	 pManager-> CalcFigureColor( arr );

	
	 int x;
	 int y;
	 while ((x= (rand()%3) +1 ) && (y=(rand()%5) +1)) 
	 {
		 if      ( x==1 && y==1 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all red rectangles "); 
		 else if ( x==1 && y==2 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all green rectangles "); 
		 else if ( x==1 && y==3 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all blue rectangles "); 
		 else if ( x==1 && y==4 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all black rectangles "); 
		 else if ( x==1 && y==5 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all white rectangles "); 

		 else if ( x==2 && y==1 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all red circles ");     
		 else if ( x==2 && y==2 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all green circles ");    
		 else if ( x==2 && y==3 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all blue circles ");     
		 else if ( x==2 && y==4 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all black circles ");    
		 else if ( x==2 && y==5 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all white circles ");    

		 else if ( x==3 && y==1 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all red triangles ");       
		 else if ( x==3 && y==2 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all green triangles ");      
		 else if ( x==3 && y==3 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all blue triangles ");       
		 else if ( x==3 && y==4 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all black triangles ");       
		 else if ( x==3 && y==5 && arr[x-1][y-1] != 0) pOut ->PrintMessage("click on all white triangles ");      
		 

		 while (countright < arr[x-1][y-1])
				{
					pIn->GetPointClicked( p.x, p.y);

					if (pManager->PickBothFunction(p.x, p.y, Copy, copycount, x, y))
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

