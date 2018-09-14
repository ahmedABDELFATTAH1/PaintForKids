#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<string>
#include<fstream>
using namespace std;

//Base class for all figures
class CFigure
{
protected:
    int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	colors Dclr;
	colors Fclr;
	string clr_name;
	types type;
	string type_name;
	string drawcolor;
	string fillcolor;
	
	
	
	/// Add more parameters if needed.

public:
	
	CFigure();
	void set_colors_of_gfxinfo();
	string  getFclr(color gclr); // it returns a color name  based on what this color is *
	string  getDclr(color gclr);
	string gettype();//return the name of the figure
	color return_DRawclr();//to be able to access to the draw color in the application manager
	color return_FRawclr();//to be able to access to the fill color in the application manager
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	void setid(int c);
	void SetIsFill(bool isf);
	CFigure(GfxInfo FigureGfxInfo);
	virtual void SetSelected(bool s) =0;	//select/unselect the figure
	virtual bool IsSelected(int ,int) =0;	//check whether fig is selected
	virtual void getSelected()=0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void print(Output* pOut) =0;
	virtual void changesize(ActionType actt) = 0;
	virtual void pastefigure(int xx,int yy) = 0;
	virtual bool bSelected()=0;
	virtual CFigure* copy() = 0;
	color getfillingcolor ();

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif