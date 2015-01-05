#include "stdafx.h"
#include "Rectangle.h"

Rec::Rec(int newX1,int newY1,int newX2,int newY2,int newWeight,COLORREF newColor)
{
	setX(newX1);
	setY(newY1);
	setWeight(newWeight);
	setColor(newColor);
	setX2(newX2);
	setY2(newY2);
}
Rec::Rec(Rec& e)
{
	setX(e.getX());
	setY(e.getY());
	setWeight(e.getWeight());
	setColor(e.getColor());
	setX2(e.getX2());
	setY2(e.getY2());
}

Rec::~Rec(void)
{
	
}

Rec &Rec::operator=(const Rec &r)
{
	setX(r.getX());
	setY(r.getY());
	setWeight(r.getWeight());
	setColor(r.getColor());
	setX2(r.getX2());
	setY2(r.getY2());
	return *this;
}
int Rec::getX2() const
{
	return x2;
}
int Rec::getY2() const
{
	return y2;
}
void Rec::setX2(const int newX2)
{
	if(newX2<0)
		x2=0;
	else
		x2=newX2;
}
void Rec::setY2(const int newY2)
{
	if(newY2<0)
		y2=0;
	else
		y2=newY2;
}
void Rec::Paint(CDC *dc)
{
	dc->MoveTo(getX(),getY());
	dc->Rectangle(getX(),getY(),getX2(),getY2());
}