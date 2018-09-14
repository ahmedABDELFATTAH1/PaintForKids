#include "CLine.h"

CLine::CLine(){}
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
		type_name = "LINE";

}

bool CLine::bSelected()
{
	return Selected;

}
void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}
void CLine::SetSelected(bool s)
{
	
		Selected = s;
	
}
bool CLine::IsSelected(int a ,int b) 
{
	if (((Corner2.x - a)*(Corner2.y - Corner1.y) - (Corner2.x - Corner1.x)*(Corner2.y - b))>=-1000&& ((Corner2.x - a)*(Corner2.y - Corner1.y) - (Corner2.x - Corner1.x)*(Corner2.y - b))<=1000)
		return true;
	else
	return false;
}
void CLine::print(Output* pOut) 
{

	auto str1 = std::to_string(Corner1.x);
	auto str2 = std::to_string(Corner1.y);
	auto str3 = std::to_string(Corner2.x);
	auto str4 = std::to_string(Corner2.y);
	auto str5 = std::to_string(ID);
	pOut->PrintMessage("start point ( " + str1 + " ," + str2 + " ) " + "---  endpoint ( " + str3 + " ," + str4 + " ) ");
}
void CLine::getSelected()
{
	if (Selected == true)
		Selected = false;
	else {

	}
}
void CLine::changesize(ActionType actt)
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

	default:
		break;
	}
}
void CLine::pastefigure(int xx, int yy)
{
	int C1x = (Corner2.x - Corner1.x) / 2;
	int C1y = (Corner2.y - Corner1.y) / 2;
	Corner1.x = xx + C1x;
	Corner1.y = yy + C1y;
	Corner2.x = xx - C1x;
	Corner2.y = yy - C1y;


}
CFigure* CLine::copy()
{
	CFigure* fig = new CLine(*this);
	return fig;

}
void CLine::Save(ofstream &OutFile) {
	OutFile << CFigure::gettype() << "     " << ID << "    " << Corner1.x << "    " << Corner1.y << "    " << Corner2.x << "    " << Corner2.y << "     " << CFigure::getDclr(CFigure::return_DRawclr()) << endl;


}

void CLine::Load(ifstream &Infile) {
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> drawcolor;
	set_colors_of_gfxinfo();
	Selected=false;
}

