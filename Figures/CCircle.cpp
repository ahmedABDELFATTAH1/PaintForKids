#pragma once
#include "CCircle.h"





CCircle::CCircle(){}
CCircle::CCircle(Point P1, Point P2,double radius, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type_name="CIRCLE";
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawcirc(Corner1, Corner2, FigGfxInfo, Selected);
}
void CCircle::SetSelected(bool s)
{
	
		Selected = s;
	
}
bool CCircle::bSelected()
{
	return Selected;

}
bool CCircle::IsSelected(int a ,int b)
{
	int r = ((Corner1.x - Corner2.x)*(Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y)*(Corner1.y - Corner2.y));
	

	int d1= ((Corner1.x - a)*(Corner1.x - a)) + ((Corner1.y - b)*(Corner1.y - b));
		int d2= ((a - Corner2.x)*(a - Corner2.x)) + ((b - Corner2.y)*(b - Corner2.y));
	if (d1<=r||d2<=r)
	{
		Radius = sqrt(abs(r));
		return true;
	}
	return false;
}
void CCircle::print(Output* pOut) 
{
	auto r1 = std::to_string(Radius);
	pOut->PrintMessage("hey i am A Circle and my RADIUS = "+ r1);
	
}
 void CCircle::getSelected()
{
	if (Selected == true)
		Selected = false;
	else {

	}
}
 void CCircle::changesize(ActionType actt)
 {
	 switch (actt)
	 {
	 case 16:

		 Corner2.x = ((Corner2.x - Corner1.x) / 4) + Corner1.x;
		 Corner2.y = ((Corner2.y - Corner1.y) / 4) + Corner1.y;
		 break;


	 case 17:
		 Corner2.x = (Corner2.x - Corner1.x) / 2 + Corner1.x;
		 Corner2.y = (Corner2.y - Corner1.y) / 2 + Corner1.y;
		 break;
	 case 18:
		 Corner2.x = (Corner2.x - Corner1.x) * 2 + Corner1.x;
		 Corner2.y = (Corner2.y - Corner1.y) * 2 + Corner1.y;
		 break;
	 case 19:
		 Corner2.x = (Corner2.x - Corner1.x) * 4 + Corner1.x;
		 Corner2.y = (Corner2.y - Corner1.y) * 4 + Corner1.y;
		 break;

	 default :
		 break;
	 }
 }
 void CCircle::pastefigure(int xx, int yy)
 {
	 int C1x = (Corner2.x - Corner1.x) / 2;
	 int C1y = (Corner2.y - Corner1.y) / 2;
	 Corner1.x = xx + C1x;
	 Corner1.y = yy + C1y;
	 Corner2.x = xx - C1x;
	 Corner2.y = yy - C1y;


 }
 CFigure* CCircle::copy()
 {
	 CFigure* fig = new CCircle(*this);
	 return fig;

 }
 void  CCircle::Save(ofstream &OutFile) {

	 OutFile << CFigure::gettype() << " "  ;
	 OutFile << ID << " ";
	 OutFile << Corner1.x << " ";
	  OutFile << Corner1.y << " ";
	  OutFile << Radius << " ";
	  color fl = CFigure::return_FRawclr();
	  color dl = CFigure::return_DRawclr();
	  string a = getDclr(dl);
	  string b = getFclr(fl);
	  OutFile << a << "    " << b << endl;
 }




 void CCircle::Load(ifstream &Infile) 
 {
	 Infile >> Corner1.x >> Corner1.y >> Radius >> drawcolor >> fillcolor;
	 Corner2.x = Corner1.x + Radius;
	 Corner2.y = Corner1.y + Radius;
	 set_colors_of_gfxinfo();
	Selected=false;
 }