#include "stdafx.h"
#include "Point.h"
Point::Point(int newX,int newY,int newWeight,COLORREF newColor)
{
	setX(newX);
	setY(newY);
	setWeight(newWeight);
	setColor(newColor);
}
Point::Point(Point &p)
{
	setX(p.getX());
	setY(p.getY());
	setWeight(p.getWeight());
	setColor(p.getColor());
}
Point::~Point()
{

}
const Point &Point::operator=(const Point &p)
{
	if(&p!=this)
	{
		setX(p.getX());
		setY(p.getY());
		setWeight(p.getWeight());
		setColor(p.getColor());
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
int Point::getWeight() const
{
	return weight;
}
COLORREF Point::getColor() const
{
	return color;
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
void Point::setWeight(const int newWeight)
{
	if(newWeight>=0)
		weight=newWeight;
	else
		weight=0;
}
void Point::setColor(const COLORREF newColor)
{
		color=newColor;
}
void Point::Paint(CDC *dc)
{
	int i;
	int tempX=getX();
	int tempY=getY();
	dc->MoveTo(tempX,tempY);
	CBrush fill(getColor());
	CPen border(PS_SOLID,1,getColor());
	dc->SelectObject(&border);
	dc->SelectObject(&fill);
	dc->Ellipse(tempX-getWeight()/2,tempY-getWeight()/2,tempX+getWeight()/2,tempY+getWeight()/2);

}
bool Point::getIsSelected()
{
	return true;
}
void Point::setIsSelected(bool newIsSelected)
{
}