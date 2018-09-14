#include "Input.h"
#include "Output.h"

Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
		
	}

	
}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
		
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
				switch (ClickedItemOrder)
				{
				case ITM_RECT: return DRAW_RECT;
				case ITM_line: return DRAW_LINE;
				case ITM_CIRC: return DRAW_CIRC;
				case ITM_EXIT: return EXIT;
				case ITM_TRIG: return DRAW_TRI;
				case ITM_white: return DRAW_White;
				case ITM_Green: return DRAW_Green;
				case ITM_Red: return DRAW_Red;
				case ITM_Black: return DRAW_Black;
				case ITM_Blue: return DRAW_Blue;
				case Savee: return SAVEE;
				case Load:return LOAD;
				case copye: return copyee;
				case cut: return cute;
				case selecte:return selectee;
				case rotate_figure:return rotatee;
				case byfour:return byqua;
				case bytwo:return bytow;
				case two:return tow;
				case four:return fooooor;
				case pastee:return pasteeee;
				case sendbacke:return back;
				case sendfront:return front;
				case board: return CHNG_FILL_CLR;
				case fille: return CHNG_DRAW_CLR;
				case delet: return DEL;
				case playmode: return TO_PLAY;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
			else {
				
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		switch (ClickedItemOrder)
			{
		 case ITM_pickbycolor : return PICK_COLOR;
		 case ITM_pickbytybe  : return PICK_TYPE;
		 case ITM_pickbyboth  : return PICK_BOTH;
		 case DRAW : return TO_DRAW;
		    }
		return TO_PLAY;	//just for now. This should be updated
		}
		
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
