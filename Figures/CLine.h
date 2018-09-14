#pragma once
#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void CLine::SetSelected(bool s);
	bool CLine::IsSelected(int,int) ;
	void CLine::print(Output* pOut) ;
	void CLine::getSelected();
	void CLine::changesize(ActionType actt);
	void CLine::pastefigure(int xx, int yy);
	bool CLine::bSelected();
	CFigure* CLine::copy();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
};

#endif