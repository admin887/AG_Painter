#include "stdafx.h"
#include "Line.h"
//#include <iostream>

Line::Line(Point newStart, Point newEnd, int newWeight, COLORREF newColor)
{
	start= newStart;
	end= newEnd;
	setWeight(newWeight);
	setColorInside(newColor);
	setColorOutside(newColor);

}
Line::Line(int newX1,int newY1,int newX2,int newY2,int newWeight, COLORREF newColor) 
{
	Point newStart(newX1,newY1);
	Point newEnd(newX2,newY2);

	setStartPoint(newStart);
	setEndPoint(newEnd);

	setWeight(newWeight);
	setColorInside(newColor);
	setColorOutside(newColor);

}
Line::Line(Line& l)
{
	setStartPoint(l.getStartPoint());
	setEndPoint(l.getEndPoint());
	setWeight(l.getWeight());
	setColorInside(l.getColorInside());
	setColorOutside(l.getColorOutside());
}

Line::~Line(void)
{
	
}

Line &Line::operator=(Line &l)
{
	setStartPoint(l.getStartPoint());
	setEndPoint(l.getEndPoint());
	setWeight(l.getWeight());
	setColorInside(l.getColorInside());
	setColorOutside(l.getColorOutside());
	return *this;
}

	Point Line::getStartPoint()
	{
		return start;
	}
	Point Line::getEndPoint()
	{
		return end;
	}
	void Line::setStartPoint(Point newStart)
	{
		start= newStart;
	}
	void Line::setEndPoint(Point newEnd)
	{
		end= newEnd;
	}

void Line::Paint(CDC *dc)
{
	dc->MoveTo(getStartPoint().getX(),getStartPoint().getY());
	dc->LineTo(getEndPoint().getX(),getEndPoint().getY());
}
