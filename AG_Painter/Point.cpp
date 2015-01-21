#include "stdafx.h"
#include "Point.h"
#pragma once
IMPLEMENT_SERIAL (Point, CObject, 1)
Point::Point(int newX,int newY,int newWeight,COLORREF newColor)
{
	setStartX(newX);
	setStartY(newY);
	setEndX(-1);
	setEndY(-1);
	setIsSelected(false);
	setWeight(newWeight);
	setColorInside(newColor);
	setColorOutside(newColor);
}
Point::Point(Point &p)
{
	setStartX(p.getStartX());
	setStartY(p.getStartY());
	setEndX(p.getEndX());
	setEndY(p.getEndY());
	setIsSelected(false);
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
		setStartX(p.getStartX());
		setStartY(p.getStartY());
		setEndX(p.getEndX());
		setEndY(p.getEndY());

		setColorInside(p.getColorInside());
		setColorOutside(p.getColorOutside());
	}
	return *this;
}
 
void Point::Paint(CDC *dc)
{
	if(getIsSelected())
	{
				CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(getColorInside());
		oldBrush=dc->SelectObject( &myBrush );        

		CPen myPen1(PS_SOLID,getWeight(), getColorInside());

		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_NOTXORPEN); 
		dc->MoveTo(getStartX(), getStartY());
		dc->Ellipse(getStartX()-getWeight()/2,getStartY()-getWeight()/2,getStartX()+getWeight()/2,getStartY()+getWeight()/2);
		
		 
		dc->SelectObject( oldPen ); 
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 

	}
	else
	{

		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(getColorInside());
		oldBrush=dc->SelectObject( &myBrush );        

		CPen myPen1(PS_SOLID,getWeight(), getColorInside());

		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		//dc->SetROP2(R2_MASKPEN); 
		dc->MoveTo(getStartX(), getStartY());
		dc->Ellipse(getStartX()-getWeight()/2,getStartY()-getWeight()/2,getStartX()+getWeight()/2,getStartY()+getWeight()/2);
		
		 
		dc->SelectObject( oldPen ); 
		//dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 

	}
}

