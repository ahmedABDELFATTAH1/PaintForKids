#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.InterfaceMode = MODE_PLAY;

	
	UI.width = 1500;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;
	UI.StatusBarHeight = 100;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 49;
	
	UI.DrawColor = RRED;	//Drawing color
	UI.FillColor = GGREEN;	//Filling color
	UI.MsgColor = RRED;		//Messages color
	UI.BkGrndColor = DARKSLATEGREY;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - TEEM 11 ON FIRE XD");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 2);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_TRIG] = "images\\MenuItems\\Menu_Trig.jpg";
	MenuItemImages[ITM_line] = "images\\MenuItems\\Menu_ss.jpg";
	MenuItemImages[ITM_Green] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_Red] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_Black] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_Blue] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[Savee] = "images\\MenuItems\\save.jpg";
	MenuItemImages[Load] = "images\\MenuItems\\load.jpg";
	MenuItemImages[copye] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[cut] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[pastee] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[selecte] = "images\\MenuItems\\select.jpg";
	MenuItemImages[rotate_figure] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[sendbacke] = "images\\MenuItems\\back.jpg";
	MenuItemImages[sendfront] = "images\\MenuItems\\front.jpg";
	MenuItemImages[fille] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[board] = "images\\MenuItems\\board.jpg";
	MenuItemImages[delet] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[playmode] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_white] = "images\\MenuItems\\white.jpg";
	MenuItemImages[byfour] = "images\\MenuItems\\byqua.jpg";
	MenuItemImages[bytwo] = "images\\MenuItems\\byhalf.jpg";
	MenuItemImages[two] = "images\\MenuItems\\double.jpg";
	MenuItemImages[four] = "images\\MenuItems\\fourtime.jpg";
	
	
	for (int i = 0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RRED, 6);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(WWHITE,5);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[ITM_pickbycolor] = "images\\MenuItems\\pickbycolor.jpg";
	MenuItemImages[ITM_pickbytybe] = "images\\MenuItems\\pickbytybe.jpg";
	MenuItemImages[ITM_pickbyboth] = "images\\MenuItems\\pickbyboth.jpg";
	MenuItemImages[DRAW] = "images\\MenuItems\\DRAWmode.jpg";
	
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RRED, 6);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
void Output::Cleartoolbar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
		
	
	pWind->SetPen(UI.MsgColor, 10);
	pWind->SetFont(30, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(500, UI.height - (int)(UI.StatusBarHeight/1), msg);
	
	
}

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}





//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	 
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,4);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
	
}
void Output::DrawTrig(Point P1, Point P2,Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,4);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y ,style);

}
void Output::Drawcirc(Point P1, Point P2, GfxInfo circGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; 
	else
		DrawingClr = circGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 4);
	drawstyle style;
	if (circGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 4);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FILLED;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

