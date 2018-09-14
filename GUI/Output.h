#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include<string>
class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		
	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawLine (Point p1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const; 
	void Output::DrawTrig(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const; //Draw a Triangle
	void Output::Drawcirc(Point P1, Point P2, GfxInfo circGfxInfo, bool selected) const;
	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void Output::Cleartoolbar() const;
	color Output::getCrntDrawColor() const;
		//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif