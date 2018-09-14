#include "CFigure.h"

CFigure::CFigure(){}


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;

}


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure:: getfillingcolor ()
{
	return FigGfxInfo.FillClr;
}

string  CFigure::getFclr(color Gclr) {
	if (FigGfxInfo.isFilled == true) {
		if (Gclr == WWHITE)
			clr_name = "WHITE";
		if (Gclr == BBLACK)
			clr_name = "BLACK";
		if (Gclr == GGREEN)
			clr_name = "GREEN";
		if (Gclr == BBLUE)
			clr_name = "BLUE";
		if (Gclr == RRED)
			clr_name = "RED";
	}
	else  clr_name = "NO-fILL";
	return clr_name;
}
string  CFigure::getDclr(color Gclr) {
	if (Gclr == WWHITE)
		clr_name = "WHITE";
	if (Gclr == BBLACK)
		clr_name = "BLACK";
	if (Gclr == GGREEN)
		clr_name = "GREEN";
	if (Gclr == BBLUE)
		clr_name = "BLUE";
	if (Gclr == RRED)
		clr_name = "RED";
	return clr_name;
}

void CFigure::setid(int x)
{
	ID = x;
}

string CFigure::gettype() {

	return type_name;

}

color CFigure::return_DRawclr() {
	return FigGfxInfo.DrawClr;
}

color CFigure::return_FRawclr() {
	return FigGfxInfo.FillClr;
}

void CFigure::set_colors_of_gfxinfo() {

	if (fillcolor == "NO-fILL")
		FigGfxInfo.FillClr=DARKSLATEGREY; 

	if (drawcolor == "WHITE")
		FigGfxInfo.DrawClr = WWHITE;
	if (drawcolor == "BLACK")
		FigGfxInfo.DrawClr = BBLACK;
	if (drawcolor == "GREEN")
		FigGfxInfo.DrawClr = GGREEN;
	if (drawcolor == "BLUE")
		FigGfxInfo.DrawClr = BBLUE;

	if (drawcolor == "RED")
		FigGfxInfo.DrawClr = RRED;

	if (fillcolor == "WHITE")
		FigGfxInfo.FillClr = WWHITE;

	if (fillcolor == "BLACK")
		FigGfxInfo.FillClr = BBLACK;

	if (fillcolor == "GREEN")
		FigGfxInfo.FillClr = GGREEN;

	if (fillcolor == "BLUE")
		FigGfxInfo.FillClr = BBLUE;

	if (fillcolor == "RED")
		FigGfxInfo.FillClr = RRED;


	if (fillcolor == "NO-FILL")
		FigGfxInfo.isFilled=false; 
		
}






