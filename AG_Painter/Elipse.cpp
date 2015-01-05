#include "stdafx.h"
#include "Elipse.h"

Elipse::Elipse(int newX1,int newY1,int newX2,int newY2,int newWeight,COLORREF newColor)
{
	setX(newX1);
	setY(newY1);
	setWeight(newWeight);
	setColor(newColor);
	setX2(newX2);
	setY2(newY2);
}
Elipse::Elipse(Elipse& e)
{
	setX(e.getX());
	setY(e.getY());
	setWeight(e.getWeight());
	setColor(e.getColor());
	setX2(e.getX2());
	setY2(e.getY2());
}

Elipse::~Elipse(void)
{
	
}

Elipse &Elipse::operator=(const Elipse &e)
{
	setX(e.getX());
	setY(e.getY());
	setWeight(e.getWeight());
	setColor(e.getColor());
	setX2(e.getX2());
	setY2(e.getY2());
	return *this;
}
int Elipse::getX2() const
{
	return x2;
}
int Elipse::getY2() const
{
	return y2;
}
void Elipse::setX2(const int newX2)
{
	if(newX2<0)
		x2=0;
	else
		x2=newX2;
}
void Elipse::setY2(const int newY2)
{
	if(newY2<0)
		y2=0;
	else
		y2=newY2;
}
void Elipse::Paint(CDC *dc)
{
	dc->MoveTo(getX(),getY());
	dc->Ellipse(getX(),getY(),getX2(),getY2());
}