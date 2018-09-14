#pragma once
#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"
#include "..\defs.h"
#include "..\GUI\Output.h"

class CCircle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	int Radius;
	
public:
	CCircle::CCircle();
	CCircle::CCircle(Point P1, Point P2, double radius, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void CCircle::SetSelected(bool s);
	bool CCircle::IsSelected(int ,int);
	void CCircle::print(Output* pOut) ;
	void CCircle::getSelected();
	void CCircle::changesize(ActionType actt);
	void CCircle::pastefigure(int xx, int yy);
	bool CCircle::bSelected();
	CFigure* CCircle::copy();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
};


#endif
