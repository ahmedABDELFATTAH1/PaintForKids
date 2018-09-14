#include "CRectangle.h"
using namespace std;

CRectangle::CRectangle(){}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type_name="RECTANGLE";
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::SetSelected(bool s)
{
	
	Selected = s; 
}
void CRectangle::getSelected()
{
	if (Selected == true)
		Selected = false;
	else {

	}
}
bool CRectangle::bSelected()
{
	return Selected;

}
bool CRectangle::IsSelected(int a, int b) 
{
		if (((a > Corner1.x&&a < Corner2.x) && (b > Corner1.y&&b < Corner2.y)) || ((a<Corner1.x&&a>Corner2.x) && (b > Corner1.y&&b < Corner2.y)) || ((a<Corner1.x&&a>Corner2.x) && (b<Corner1.y&&b>Corner2.y)) || ((a > Corner1.x&&a < Corner2.x) && (b > Corner1.y&&b < Corner2.y)))
			
			{
					return true;
					
			}
			else
			{
				return false;
			}
		
	}
void CRectangle::print(Output* pOut) 
{
	int l= getlength();
	int w= getwidth();
	auto str1 = std::to_string(l);
	auto str2 = std::to_string(w);
	pOut->PrintMessage("The Rectangle Length  = "+str1+" and the width = "+str2);
}

double CRectangle::getlength() 
{

	double lenght = abs(Corner2.x - Corner1.x);
	return lenght;
}
double CRectangle::getwidth() 
{
	double width = abs(Corner2.y - Corner1.y);
	return width;
}
void CRectangle::changesize(ActionType actt)
{
	switch (actt)
	{
	case 16:
		
		Corner2.x = ((Corner2.x - Corner1.x) / 4)+Corner1.x;
		Corner2.y = ((Corner2.y - Corner1.y) / 4) + Corner1.y;
		break;
		
		
	case 17:
		Corner2.x = (Corner2.x - Corner1.x) / 2+ Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) / 2+ Corner1.y;
		break;
	case 18:
		Corner2.x = (Corner2.x - Corner1.x) * 2+ Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 2+ Corner1.y;
		break;
	case 19:
		Corner2.x = (Corner2.x - Corner1.x) * 4+ Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 4+ Corner1.y;
		break;

	default:
		break;
	}
}
void CRectangle::pastefigure(int xx,int yy)
{

	int C1x = (Corner2.x - Corner1.x)/2;
	int C1y = (Corner2.y - Corner1.y)/2;
	Corner1.x = xx + C1x;
	Corner1.y = yy + C1y;
	Corner2.x = xx - C1x;
	Corner2.y = yy - C1y;

}
CFigure* CRectangle::copy()
{
	CFigure* fig = new CRectangle(*this);
//	cout<< "hey iam in Crectangle" << endl;
	return fig;

}
void CRectangle::Save(ofstream &OutFile) {
	color fcolor = return_FRawclr();
	string fcolorstr = getFclr(fcolor);
	OutFile << gettype() << "    " << ID << "    " << Corner1.x << "      " << Corner1.y << "     " << Corner2.x << "      " << Corner2.y << "    " << getDclr(return_DRawclr()) << "    " << fcolorstr << endl;
}


void CRectangle::Load(ifstream &Infile) {
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> drawcolor >> fillcolor;
	set_colors_of_gfxinfo();
	Selected=false;
	
}
