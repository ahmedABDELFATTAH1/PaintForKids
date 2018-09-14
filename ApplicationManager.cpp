#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTrigAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddSelectAction.h"
#include "Actions\DrawColor.h"
#include "Actions\FillColor.h"
#include "Actions\Deletee.h"
#include "Actions\Resizeaction.h"
#include "Actions\copyy.h"
#include "Actions\sendfrontt.h"
#include "Actions\sendback.h"
#include "Actions\cutt.h"
#include "Actions\pasteee.h"
#include "Actions\changetoplay.h"
#include "Actions\ToDrawAction.h"
#include "Actions\PickTypeAction.h"
#include "Actions\PickColorAction.h"
#include "Actions\PickBothAction.h"
#include "Figures\CCircle.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include <fstream>
#include "Actions\loadd.h"
#include "Actions\savee.h"
#include"Actions\Exit.h"


ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	Iselected = -1;
	FigCount = 0;
	SelectedFig = NULL;
	Clipboard = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTrigAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;
		case selectee:
			pAct = new AddSelectAction(this);
			break;
		case rotatee:
			pAct = new Resizeaction(this);
			break;
		case copyee:
			pAct = new copyy(this);
			break;
		case cute:
			pAct = new cutt(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new FillColor(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new DrawColor(this);
			break;
		case pasteeee:
			pAct = new pasteee(this);
			break;
		case front:
			pAct = new sendfrontt(this);
			break;
		case back:
			pAct = new sendback(this);
			break;

		case TO_PLAY:
			pAct = new changetoplay(this);
			break;

		case DEL:
			pAct = new Deletee(this);
			break;

		case TO_DRAW:
			pAct = new ToDrawAction (this);
			break;

		case PICK_TYPE:
			pAct = new PickTypeAction (this);
			break;
		case PICK_COLOR:
			pAct = new PickColorAction (this);
			break;

		case PICK_BOTH:
			pAct = new PickBothAction (this);
			break;
				case SAVEE:
			pAct = new savee(this);
			break;
		case LOAD:
			pAct = new loadd(this);
			break;
		case EXIT:
			pAct = new Exit(this);
		break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
	for (int i = (FigCount-1); i >=0 ; i--)
	{

		if (FigList[i]->IsSelected(x, y))
		{
			if (FigList[i]->bSelected())
				FigList[i]->SetSelected(false);
			else {
				FigList[i]->SetSelected(true);
		}
			for (int co = (FigCount - 1); co >= 0; co--)
			{
				if (co != i)
				{
					if (FigList[co]->bSelected())
					{
						FigList[co]->SetSelected(false);
						
					}
				}
		}
			Iselected = i;
			SelectedFig = FigList[i];
			return FigList[i];
		}
			
			
		}
		
	
	
	
	return NULL;}

 void ApplicationManager::printinfo(CFigure * cufigure) const
{
	 if(cufigure!=NULL)
	 cufigure->print(pOut);
	 
}

void ApplicationManager::Drawselected(color a)
 {

	
	SelectedFig->ChngDrawClr(a);
	SelectedFig->getSelected();
	SelectedFig=NULL;
	
 }
void ApplicationManager::changesize(ActionType a)
{
	SelectedFig->changesize(a);

}
void ApplicationManager::Fillselected(color a)
{
	
	
		SelectedFig->ChngFillClr(a);
		SelectedFig->getSelected();
		SelectedFig = NULL;
		
}
void ApplicationManager::pastethefigure(int ppx,int ppy)
{
	if (Clipboard)
	{

		CFigure* temp=Clipboard->copy();
		temp->pastefigure(ppx, ppy);
		int nomfig = getfigcount();
		FigList[nomfig] = temp;
		FigCount++;
		Clipboard->SetSelected(false);
		

	}

}

void ApplicationManager::changetoplaymode()
{


}

bool ApplicationManager::isis()
{
	if (SelectedFig==NULL)
		return false;
	else {
		return true;
	}
}
void ApplicationManager::UpdateInterface() const
{
	
	pOut->ClearDrawArea();
	for (int i = 0; i<FigCount; i++)
		FigList[i]->Draw(pOut);
	
	
	
	//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
//////////////////////////////////////////////////////////////////////////////////////

CFigure* ApplicationManager::getselectedfig()
{

	int i = getIselected();
	CFigure*m = FigList[i];
	return m;
}

void ApplicationManager::setclipboard()
{
	Clipboard = getselectedfig()->copy();
	Clipboard->SetSelected(false);
}

CFigure * ApplicationManager::getClipboard() const 
{
	return Clipboard; 
}

void ApplicationManager::Nselect()
{
	if (SelectedFig)
	{
		SelectedFig->SetSelected(false);
		SelectedFig = NULL;

	}

}
void ApplicationManager::clear() {
	for (int i = 0; i < FigCount; i++) {
		 delete FigList[i];
	}
	FigCount = 0;

}
void ApplicationManager::plusid() {

	for (int i = 0; i < MaxFigCount; i++) {

		if (FigList[i] != NULL)
			FigList[i]->setid(i + 1);

	}
}
void ApplicationManager::saveall(ofstream &OutFile) {

	plusid();
	color i;
	string a;
	a=FigList[FigCount-1]->getDclr(UI.DrawColor);
	OutFile <<a;

	
	
	string b;
	b=FigList[FigCount-1]->getFclr(UI.FillColor);
	OutFile <<b;
    OutFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}

}

bool ApplicationManager::issellected()
{
	if (SelectedFig||Clipboard!=NULL)
		return true;
	else
		return false;
}


int ApplicationManager::getIselected()
{
	return Iselected;
}

int ApplicationManager::getfigcount()
{
	return FigCount;
}

void ApplicationManager::del()
{
	if (SelectedFig)
	{
		int i = 0;
		int x = getIselected();
		int y = FigCount;
		FigList[x] = NULL;
		for (i = x; i<y; i++)
		{
			FigList[i] = FigList[i + 1];

		}
		FigCount = FigCount - 1;
		FigList[y - 1] = NULL;
		SelectedFig = NULL;
	}
}

void ApplicationManager::sendfront()
{
	if (SelectedFig)
	{
		int i = 0;
		CFigure* lastf = SelectedFig;
		int nomfigure = FigCount - 1;
		int x = getIselected();
		for (i = x; i<nomfigure; i++)
		{
			FigList[i] = FigList[i + 1];
		}
		FigList[nomfigure] = lastf;
		SelectedFig = NULL;
	}

}

void ApplicationManager::sentback()
{
	if (SelectedFig)
	{
		int i = 0;
		int x = getIselected();
		CFigure* lastf = SelectedFig;
		for (i = x; i>0; i--)
		{
			FigList[i] = FigList[i - 1];
		}
		FigList[0] = lastf;
		SelectedFig = NULL;
	}

}

void  ApplicationManager ::CalcNumOfColors ( int * typeArray, int size)
{
	for ( int i=0 ; i< FigCount ; i++)
	{
		if ( FigList[i]->getfillingcolor() == RRED )        (typeArray[0])++;
		else if ( FigList[i]->getfillingcolor() == GGREEN ) (typeArray[1])++;
	    else if ( FigList[i]->getfillingcolor() == BBLUE )  (typeArray[2])++;
		else if ( FigList[i]->getfillingcolor() == BBLACK ) (typeArray[3])++;
		else if ( FigList[i]->getfillingcolor() == WWHITE ) (typeArray[4])++;

	}
}
void ApplicationManager :: CalcNumOfShapes( int * typeArray, int size)
{
   for ( int i=0 ; i< FigCount ; i++)
	 {
		 
		 if (( dynamic_cast < CRectangle *>  ( FigList[i] ) ) != 0 )
			 (typeArray[0])++;

		 else if (( dynamic_cast < CCircle * >  ( FigList[i] ) ) != 0 )
			 (typeArray[1])++;
		
		 else if (( dynamic_cast < CTriangle  * >  ( FigList[i] ) ) != 0 )
			(typeArray[2])++;

		 else if (( dynamic_cast < CLine * >  ( FigList[i] ) ) != 0 )
			 (typeArray[3])++;
	 }
}

void ApplicationManager::UpdateCopyInterface(CFigure** copy , int size ) const
{	
	for(int i=0; i<size ; i++)
		copy[i]->Draw(pOut);		
}

void ApplicationManager::  CopyArray (CFigure ** copy)
{
	
	for ( int i=0; i< FigCount ; i++)
	{
		copy[i]= FigList[i];
	}
	
}

bool ApplicationManager :: pointInFigure (int x, int y, CFigure ** c , int & size, int fig)
{
	bool flag=false;
	bool f;
	for (int i=0; i<size ; i++)
	{
		if ( fig==1)
		{
			if (( dynamic_cast < CRectangle *>  ( c[i] ) ) != 0 )
				flag= c[i]->IsSelected(x,y);
		}
		else if ( fig==2)
		{
			if (( dynamic_cast < CCircle *>  ( c[i] ) ) != 0 )
				flag= c[i]->IsSelected(x,y);
		}
		else if ( fig==3)
		{
			if (( dynamic_cast < CTriangle *>  ( c[i] ) ) != 0 )
				flag= c[i]->IsSelected(x,y);
		}
		else if ( fig==4)
		{
			if (( dynamic_cast < CLine *>  ( c[i] ) ) != 0 )
				flag= c[i]->IsSelected(x,y);
		}

		f=  c[i]->IsSelected(x,y);
		if (f)
		{
			c[i]= c [size-1];
			
			size--;
			pOut->ClearDrawArea();
			UpdateCopyInterface(c, size);
		}
		if (flag) return flag;
	}

	return flag;
}
  bool ApplicationManager :: FigureFillColor(int x, int y, CFigure ** c , int & size, int fig)
{
	bool flag=false;
	bool f;
	for (int i=0; i<size ; i++)
	{
		if ( fig == 1)
		{
			if (c[i]->IsSelected(x,y))
			{
				if (c[i]->getfillingcolor() == RRED ) 
					flag=true;
			}
		}
		else if ( fig == 2)
		{
			if (c[i]->IsSelected(x,y))
			{
				if (c[i]->getfillingcolor() == GGREEN ) 
					flag=true;
			}
		}
		else if ( fig == 3)
		{
			if (c[i]->IsSelected(x,y))
			{
				if (c[i]->getfillingcolor() == BBLUE ) 
					flag=true;
			}
		}
		else if ( fig == 4)
		{
			if (c[i]->IsSelected(x,y))
			{
				if (c[i]->getfillingcolor() == BBLACK ) 
					flag=true;
			}
		}
		else if ( fig == 5)
		{
			if (c[i]->IsSelected(x,y))
			{
				if (c[i]->getfillingcolor() == WWHITE ) 
					flag=true;
			}
		}
		f=  c[i]->IsSelected(x,y);
		if (f)
		{
			c[i]= c [size-1];
			size--;
			pOut->ClearDrawArea();
			UpdateCopyInterface(c, size);
		}
		if (flag) return flag;
	}
	return flag;
}

  bool ApplicationManager :: PickBothFunction(int x, int y, CFigure ** c , int & size, int fig, int col)
{
	
	bool f=false ;
	bool fc= false ;
	color clr;
	for (int i=0; i<size ; i++)
	{
		if (fig ==1 )
		{
			if (( dynamic_cast < CRectangle *>  ( c[i] ) ) != 0 )
				f= c[i]->IsSelected(x,y);
			clr= c[i]->getfillingcolor();
		}
		if (fig ==2 )
		{
			if (( dynamic_cast < CCircle *>  ( c[i] ) ) != 0 )
				f= c[i]->IsSelected(x,y);
			clr= c[i]->getfillingcolor();
		}
		if (fig ==3 )
		{
			if (( dynamic_cast < CTriangle *>  ( c[i] ) ) != 0 )
				f= c[i]->IsSelected(x,y);
			clr= c[i]->getfillingcolor();
		}
		if      ( col==1 && clr == RRED ) fc=true;
		else if ( col==2 && clr == GGREEN ) fc=true;
		else if ( col==3 && clr == BBLUE ) fc=true;
		else if ( col==4 && clr == BBLACK ) fc=true;
		else if ( col==5 && clr == WWHITE ) fc=true;

		f= c[i]->IsSelected(x,y);
		if (f)
		{
			c[i]= c [size-1];
			size--;
			pOut->ClearDrawArea();
			UpdateCopyInterface(c, size);
		}
		if ( f && fc ) return true ;

	}
	return false;
  }
  void ApplicationManager :: CalcFigureColor(int typeArray [3][5])
{
	
		 
	for ( int i=0 ; i< FigCount ; i++)
	 {
		 
		 if (( dynamic_cast < CRectangle *>  ( FigList[i] ) ) != 0 )
		 {
			  if (FigList[i]->getfillingcolor() == RRED ) (typeArray[0][0])++ ;
			  else if (FigList[i]->getfillingcolor() == GGREEN ) (typeArray[0][1])++;
			  else if (FigList[i]->getfillingcolor() == BBLUE ) (typeArray[0][2])++;
			  else if (FigList[i]->getfillingcolor() == BBLACK ) (typeArray[0][3])++;
			  else if (FigList[i]->getfillingcolor() == WWHITE) (typeArray[0][4])++;
		 }

		 else if (( dynamic_cast < CCircle * >  ( FigList[i] ) ) != 0 )
		 {
			  if (FigList[i]->getfillingcolor() == RRED ) (typeArray[1][0])++;
			  else if (FigList[i]->getfillingcolor() == GGREEN ) (typeArray[1][1])++;
			  else if (FigList[i]->getfillingcolor() == BBLUE ) (typeArray[1][2])++;
			  else if (FigList[i]->getfillingcolor() == BBLACK ) (typeArray[1][3])++;
			  else if (FigList[i]->getfillingcolor() == WWHITE) (typeArray[1][4])++;
		 }
		

		 else if (( dynamic_cast < CTriangle * >  ( FigList[i] ) ) != 0 )
		 {
			  if (FigList[i]->getfillingcolor() == RRED ) (typeArray[2][0])++;
			  else if (FigList[i]->getfillingcolor() == GGREEN ) (typeArray[2][1])++;
			  else if (FigList[i]->getfillingcolor() == BBLUE ) (typeArray[2][2])++;
			  else if (FigList[i]->getfillingcolor() == BBLACK ) (typeArray[2][3])++;
			  else if (FigList[i]->getfillingcolor() == WWHITE) (typeArray[2][4])++;
		 }
	 }
	
}
//Destructor

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
