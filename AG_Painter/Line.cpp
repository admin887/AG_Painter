#include "stdafx.h"
#include "Line.h"
//#include <iostream>

Line::Line(int newX1,int newY1,int newX2,int newY2) 
{
	setX(newX1);
	setY(newY1);
	setX2(newX2);
	setY2(newY2);
}
Line::Line(Line& l)
{
	setX(l.getX());
	setY(l.getY());
	setX2(l.getX2());
	setY2(l.getY2());
}

Line::~Line(void)
{
	
}

Line &Line::operator=(const Line &l)
{
	setX(l.getX());
	setY(l.getY());
	setX2(l.getX2());
	setY2(l.getY2());

	return *this;
}

int Line::getX2() const
{
	return m_X2;
}

int Line::getY2() const
{
	return m_Y2;
}

void Line::setX2(int newX2)
{
	m_X2= newX2;
}
void Line::setY2(int newY2)
{
	m_Y2= newY2;
}
void Line::Paint(CDC *dc)
{
	dc->MoveTo(getX(),getY());
	dc->LineTo(getX2(),getY2());
}
