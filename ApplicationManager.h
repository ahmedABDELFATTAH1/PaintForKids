#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int Iselected;
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	int pastepoint;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void printinfo(CFigure * cufigure) const;
	void Drawselected(color a);
	void Fillselected(color a);
	bool isis();
	CFigure* getselectedfig();
	void Nselect();
	bool issellected();
	int getIselected();
	int getfigcount();
	void del();
	void sendfront();
	void sentback();
	void changesize(ActionType a);
	void pastethefigure(int ppx, int ppy);
	bool isclipboard();
	void setclipboard();
	CFigure * getClipboard() const;
	void changetoplaymode();
	bool pointInFigure (int x, int y, CFigure ** c , int & size, int fig);
	void CopyArray (CFigure **);
	void UpdateCopyInterface(CFigure ** , int size ) const;
	void CalcNumOfShapes( int * typeArray, int size);
	bool FigureFillColor(int x, int y, CFigure ** c , int & size, int fig);
	void CalcNumOfColors ( int * typeArray, int size);
	void CalcFigureColor(int typeArray[3][5]);
	bool PickBothFunction(int x, int y, CFigure ** c , int & size, int fig, int col);
	void saveall(ofstream &OutFile);
	void loadall(ifstream &InFile);
	void plusid();
	void clear();
};

#endif