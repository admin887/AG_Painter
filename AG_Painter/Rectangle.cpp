#include "stdafx.h"
#include "Rectangle.h"
#pragma once

Rec::Rec(Point newP1, Point newP2,int newWeight, COLORREF newInsideColor, COLORREF newOutsideColor)
{
	setStartX(newP1.getStartX());
	setStartY(newP1.getStartY());

	setEndX(newP2.getStartX());
	setEndY(newP2.getStartY());
	setIsSelected(false);
	setWeight(newWeight);
	setColorOutside(newOutsideColor);
	setColorInside(newInsideColor);

}
Rec::Rec(int newX1,int newY1,int newX2,int newY2,int newWeight, COLORREF newInsideColor, COLORREF newOutsideColor)
{
	setStartX(newX1);
	setStartY(newY1);
	setIsSelected(false);
	setEndX(newX2);
	setEndY(newY2);
	
	
	setWeight(newWeight);
	setColorInside(newInsideColor);
	setColorOutside(newOutsideColor);
	
}
Rec::Rec(Rec& e)
{
	setStartX(e.getStartX());
	setStartY(e.getStartY());
	setEndX(e.getEndX());
	setEndY(e.getEndY());
	setIsSelected(false);
	setWeight(e.getWeight());
	setColorOutside(e.getColorOutside());
	setColorInside(e.getColorInside());
}

Rec::~Rec(void)
{
	
}

Rec &Rec::operator=(Rec &r)
{
	setStartX(r.getStartX());
	setStartY(r.getStartY());
	setEndX(r.getEndX());
	setEndY(r.getEndY());

	setWeight(r.getWeight());
	setColorOutside(r.getColorOutside());
	setColorInside(r.getColorInside());
	return *this;
}

void Rec::Paint(CDC *dc)
{
	CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(getColorInside());
		oldBrush=dc->SelectObject( &myBrush );        

		CPen myPen1(PS_SOLID,getWeight(), getColorOutside());

		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		dc->SetROP2(R2_NOTXORPEN);  
		dc->MoveTo(getStartX(), getStartY());
		dc->Rectangle(getStartX(), getStartY(),getEndX(), getEndY());
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

