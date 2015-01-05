#include "stdafx.h"
#include "Point.h"
Point::Point(int newX,int newY,int newWeight,COLORREF newColor)
{
	setX(newX);
	setY(newY);
	setWeight(newWeight);
	setColorInside(newColor);
	setColorOutside(newColor);
}
Point::Point(Point &p)
{
	setX(p.getX());
	setY(p.getY());
	setWeight(p.getWeight());
	setColorInside(p.getColorInside());
	setColorOutside(p.getColorOutside());
}
Point::~Point()
{
}
const Point &Point::operator=(Point &p)
{
	if(&p!=this)
	{
		setX(p.getX());
		setY(p.getY());
		setColorInside(p.getColorInside());
		setColorOutside(p.getColorOutside());
	}
	return *this;
}
 int Point::getX() const
{
	return x;
}
int Point::getY() const
{
	return y;
}


void Point::setX(const int newX)
{
	if(newX<0)
		x=0;
	else
		x=newX;
}
void Point::setY(const int newY)
{
	if(newY<0)
		y=0;
	else
		y=newY;
}
void Point::Paint(CDC *dc)
{
	int i;
	int tempX=getX();
	int tempY=getY();
	dc->MoveTo(tempX,tempY);
	CBrush fill(getColorInside());
	CPen border(PS_SOLID,1,getColorInside());
	dc->SelectObject(&border);
	dc->SelectObject(&fill);
	dc->Ellipse(tempX-getWeight()/2,tempY-getWeight()/2,tempX+getWeight()/2,tempY+getWeight()/2);

}

