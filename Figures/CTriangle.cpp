#include "CTriangle.h"
CTriangle::CTriangle(){}
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	type_name="TRIANGLE";
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTrig(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}
void CTriangle::SetSelected(bool s)
{
		Selected = s;
	
}
bool CTriangle::IsSelected(int a , int b) 
{
	int A, A1, A2, A3;
	A = .5*abs((Corner3.x - Corner1.x)*(Corner2.y - Corner1.y) - (Corner3.y - Corner1.y)*(Corner2.x - Corner1.x));
	A1 = .5*abs((Corner1.x - a)*(Corner3.y - b) - (Corner3.x - a)*(Corner1.y - b));
	A2 = .5*abs((Corner1.x - a)*(Corner2.y - b) - (Corner2.x - a)*(Corner1.y - b));
	A3 = .5*abs((Corner3.x - a)*(Corner2.y - b) - (Corner2.x - a)*(Corner3.y - b));
	if (A-(A1+A2+A3)>=-2&& A - (A1 + A2 + A3)<=2)
    {
		return true;
	}
	else
	{
		return false;
	}
}
void CTriangle::print(Output* pOut) 
{

	auto str1 = std::to_string(Corner1.x);
	auto str2 = std::to_string(Corner1.y);
	auto str3 = std::to_string(Corner2.x);
	auto str4 = std::to_string(Corner2.y);
	auto str5 = std::to_string(Corner3.x);
	auto str6 = std::to_string(Corner3.y);
	
	pOut->PrintMessage("first point ( " + str1 + " ," + str2 + " ) " + "--- second point ( " + str3 + " ," + str4 + " ) "+ "------third point ( " + str5 + " ," + str6 + " ) ");
}
void CTriangle::getSelected()
{
	if (Selected == true)
		Selected = false;
	else {

	}
}
void CTriangle::changesize(ActionType actt)
{

	switch (actt)
	{
	case 16:

		Corner2.x = ((Corner2.x - Corner1.x) / 4) + Corner1.x;
		Corner2.y = ((Corner2.y - Corner1.y) / 4) + Corner1.y;
		Corner3.x = ((Corner3.x - Corner1.x) / 4) + Corner1.x;
		Corner3.y = ((Corner3.y - Corner1.y) / 4) + Corner1.y;
		break;


	case 17:
		Corner2.x = (Corner2.x - Corner1.x) / 2 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) / 2 + Corner1.y;
		Corner3.x = ((Corner3.x - Corner1.x) / 2) + Corner1.x;
		Corner3.y = ((Corner3.y - Corner1.y) / 2) + Corner1.y;
		break;
	case 18:
		Corner2.x = (Corner2.x - Corner1.x) * 2 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 2 + Corner1.y;
		Corner3.x = ((Corner3.x - Corner1.x) *2) + Corner1.x;
		Corner3.y = ((Corner3.y - Corner1.y) *2) + Corner1.y;
		break;
	case 19:
		Corner2.x = (Corner2.x - Corner1.x) * 4 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 4 + Corner1.y;
		Corner3.x = ((Corner3.x - Corner1.x) * 4) + Corner1.x;
		Corner3.y = ((Corner3.y - Corner1.y) * 4) + Corner1.y;
		break;

	default:
		break;
	}
}
void CTriangle::pastefigure(int xx, int yy)
{
	int PO1x = xx - Corner1.x;
	int PO1y = yy - Corner1.y;
	Corner1.x = xx;
	Corner1.y = yy;
	Corner2.x = Corner2.x + PO1x;
	Corner2.y = Corner2.y + PO1y;
	Corner3.x = Corner3.x + PO1x;
	Corner3.y = Corner3.y + PO1y;
	


}
bool CTriangle::bSelected()
{
	return Selected;

}
CFigure* CTriangle::copy()
{
	CFigure* fig = new CTriangle(*this);
	return fig;

}
void  CTriangle::Save(ofstream &OutFile) {

	OutFile << CFigure::gettype() << "    " << ID << "    " << Corner1.x << "    " << Corner1.y << "    " << Corner2.x << "     " << Corner2.y <<"    " <<Corner3.x<<"     " <<Corner3.y<<"    " <<CFigure::getDclr(CFigure::return_DRawclr()) << "    " << CFigure::getFclr(CFigure::return_FRawclr()) << endl;


}

void CTriangle::Load(ifstream &Infile) {
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> drawcolor >> fillcolor;
	set_colors_of_gfxinfo();
	Selected=false;

}
