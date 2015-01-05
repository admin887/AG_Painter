#include "stdafx.h"
#include "Rectangle.h"

Rec::Rec(Point newP1, Point newP2,int newWeight, COLORREF newInsideColor, COLORREF newOutsideColor)
{
	setP1(newP1);
	setP2(newP2);
	setWeight(newWeight);
	setColorOutside(newOutsideColor);
	setColorInside(newInsideColor);

}
Rec::Rec(int newX1,int newY1,int newX2,int newY2,int newWeight, COLORREF newInsideColor, COLORREF newOutsideColor)
{
	Point *p1= new Point();
	Point *p2= new Point();
	p1->setX(newX1);
	p1->setY(newY1);
	p2->setX(newX2);
	p2->setY(newY2);

	setP1(*p1);
	setP2(*p2);
	
	setWeight(newWeight);
	setColorInside(newInsideColor);
	setColorOutside(newOutsideColor);
	
}
Rec::Rec(Rec& e)
{
	setP1(e.getP1());
	setP2(e.getP2());
	setWeight(e.getWeight());
	setColorOutside(e.getColorOutside());
	setColorInside(e.getColorInside());
}

Rec::~Rec(void)
{
	
}

Rec &Rec::operator=(Rec &r)
{
	setP1(r.getP1());
	setP2(r.getP2());
	setWeight(r.getWeight());
	setColorOutside(r.getColorOutside());
	setColorInside(r.getColorInside());
	return *this;
}

void Rec::Paint(CDC *dc)
{
	dc->MoveTo(getP1().getX(), getP1().getY());
	dc->Rectangle(getP1().getX(), getP1().getY(),getP2().getX(), getP2().getY());
}

void Rec::setP1(Point newP1)
{
	m_p1= newP1;
}
void Rec::setP2(Point newP2)
{
	m_p2= newP2;
}
Point Rec::getP1()
{
	return m_p1;
}
Point Rec::getP2()
{
	return m_p2;
}