#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	//Draw Line
	DRAW_RECT,
	DRAW_LINE,	//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,
	DRAW_White,
	DRAW_Green,
	DRAW_Red,
	DRAW_Black,
	DRAW_Blue,
	SAVEE,
	LOAD,
	copyee,
	cute,
	selectee,
	changee,
	rotatee,
	byqua,
	bytow,
	tow,
	fooooor,
	front,
	back,
	CHNG_DRAW_CLR,
	CHNG_FILL_CLR,
	DEL,
	MOVE,
	EXIT,	
	
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	pasteeee,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode

	PICK_COLOR,
	PICK_TYPE,
	PICK_BOTH,
	
	

	
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};
enum types {

	CIRCa,
	LINEa,
	RECTa,
	TRIGa,

};
enum colors {
	WHITE,
	BLACK,
	GREEN,
	BLUE,
	RED,
	nofill,

};
#endif