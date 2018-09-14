#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include "..\defs.h"
#include "..\GUI\Output.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	void CRectangle::SetSelected(bool s);
	bool CRectangle::IsSelected(int , int) ;
	void CRectangle::print(Output* pOut)  ;
	double CRectangle::getlength();
	double CRectangle::getwidth();
	bool CRectangle::bSelected();
	void CRectangle::changesize(ActionType actt);
	void CRectangle::getSelected();
	void CRectangle::pastefigure(int xx, int yy);
	CFigure* CRectangle::copy();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	
	
};

#endif