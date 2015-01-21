#include "stdafx.h"
#include "Line.h"
#pragma once
//#include <iostream>
IMPLEMENT_SERIAL (Line, CObject, 1)
Line::Line(Point newStart, Point newEnd, int newWeight, COLORREF newColor)
{

	setStartX(newStart.getStartX());
	setStartY(newStart.getStartY());

	setEndX(newEnd.getStartX());
	setEndY(newEnd.getStartY());
	setIsSelected(false);
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
	setIsSelected(false);
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
	setIsSelected(false);
	setWeight(l.getWeight());
	setColorInside(l.getColorInside());
	setColorOutside(l.getColorOutside());
}

Line::~Line(void)
{
	
}

Line &Line::operator=(const Line &l)
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
	CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(getColorInside());
		oldBrush=dc->SelectObject( &myBrush );        
		CPen myPen1(PS_SOLID,getWeight(), getColorOutside());
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_NOTXORPEN);  
		dc->MoveTo(getStartX(),getStartY());
		dc->LineTo(getEndX(),getEndY());
		dc->SelectObject( oldPen ); 
		dc->SetROP2(R2_COPYPEN);  
		dc->SelectObject( oldBrush ); 

		if(getIsSelected())
		{
			dc->SetROP2(R2_NOTXORPEN);  
			CRectTracker track;
			CPoint pStart(getStartX(),getStartY()),pEnd(getEndX(),getEndY());
			track.m_rect.SetRect(pStart,pEnd);
			track.m_nStyle=CRectTracker::dottedLine^CRectTracker::resizeOutside;
			track.Draw(dc);
		}
}
