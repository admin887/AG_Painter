#include "stdafx.h"
#include "Elipse.h"

Elipse::Elipse(Point newP1, Point newP2,int newWeight, COLORREF newInsideColor, COLORREF newOutsideColor)
{
	setStartX(newP1.getStartX());
	setStartY(newP1.getStartY());

	setEndX(newP2.getStartX());
	setEndY(newP2.getStartY());

	setWeight(newWeight);
	setColorOutside(newOutsideColor);
	setColorInside(newInsideColor);

}
Elipse::Elipse(int newX1,int newY1,int newX2,int newY2,int newWeight, COLORREF newInsideColor, COLORREF newOutsideColor)
{
	setStartX(newX1);
	setStartY(newY1);

	setEndX(newX2);
	setEndY(newY2);
	
	
	setWeight(newWeight);
	setColorInside(newInsideColor);
	setColorOutside(newOutsideColor);
	
}
Elipse::Elipse(Elipse& e)
{
	setStartX(e.getStartX());
	setStartY(e.getStartY());
	setEndX(e.getEndX());
	setEndY(e.getEndY());

	setWeight(e.getWeight());
	setColorOutside(e.getColorOutside());
	setColorInside(e.getColorInside());
}

Elipse::~Elipse(void)
{
	
}

Elipse &Elipse::operator=(Elipse &r)
{
	setStartX(r.getStartX());
	setStartY(r.getStartY());
	setEndX(r.getEndX());
	setEndY(r.getEndY());

	setWeight(r.getWeight());
	setColorOutside(r.getColorOutside());
	setColorInside(r.getColorInside());
	return *this;
}

void Elipse::Paint(CDC *dc)
{
	dc->MoveTo(getStartX(), getStartY());
	dc->Ellipse(getStartX(), getStartY(),getEndX(), getEndY());
}

