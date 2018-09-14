#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle::CTriangle();
	CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void  CTriangle::SetSelected(bool s);
	bool  CTriangle::IsSelected(int , int);
	void CTriangle::print(Output* pOut) ;
	void CTriangle::getSelected();
	void CTriangle::changesize(ActionType actt);
	void CTriangle::pastefigure(int xx, int yy);
	bool CTriangle::bSelected();
	CFigure* CTriangle::copy();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	
};

#endif
