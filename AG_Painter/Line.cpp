#include "stdafx.h"
#include "Line.h"
//#include <iostream>

Line::Line(Point newStart, Point newEnd, int newWeight, COLORREF newColor)
{

	setStartX(newStart.getStartX());
	setStartY(newStart.getStartY());

	setEndX(newEnd.getStartX());
	setEndY(newEnd.getStartY());


	setWeight(newWeight);
	setColorInside(newColor);
	setColorOutside(newColor);

}
Line::Line(int newX1,int newY1,int newX2,int newY2,int newWeight, COLORREF newColor) 
{
	setStartX(newX1);
	setStartY(newY1);

	setEndX(newX2);
	setEndY(newY2);

	setWeight(newWeight);
	setColorInside(newColor);
	setColorOutside(newColor);

}
Line::Line(Line& l)
{
	setStartX(l.getStartX());
	setStartY(l.getStartY());

	setEndX(l.getEndX());
	setEndY(l.getEndY());

	setWeight(l.getWeight());
	setColorInside(l.getColorInside());
	setColorOutside(l.getColorOutside());
}

Line::~Line(void)
{
	
}

Line &Line::operator=(Line &l)
{
	setStartX(l.getStartX());
	setStartY(l.getStartY());

	setEndX(l.getEndX());
	setEndY(l.getEndY());

	setWeight(l.getWeight());
	setColorInside(l.getColorInside());
	setColorOutside(l.getColorOutside());
	return *this;
}

void Line::Paint(CDC *dc)
{
	dc->MoveTo(getStartX(),getStartY());
	dc->LineTo(getEndX(),getEndY());
}
