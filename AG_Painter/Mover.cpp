#include "stdafx.h"
#include "selector.h"
#include "NullShape.h"
#include <algorithm>
#include <iterator>
#include "Mover.h"
#pragma once
Mover::Mover(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
	setIsSelected(false);
}
Mover::Mover(Mover &newMover)
{
	setShapeGarage(*newMover.getShapeGarage());
	setIsSelected(newMover.getIsSelected());
}
Mover &Mover::operator=(Mover &newMover)
{
	setShapeGarage(*newMover.getShapeGarage());
	setIsSelected(newMover.getIsSelected());
	return *this;
}
Shape* Mover::getMfoundShape()
{
	return m_FoundedShape;
}
void Mover::setMfoundShape(Shape* newMfoundShape)
{
	m_FoundedShape=newMfoundShape;
}
CPoint* Mover::getFpoint()
{
	return &m_fPoint;
}
void Mover::setFpoint(CPoint newFpoint)
{
	m_fPoint=newFpoint;
}
void Mover::MouseDown(CDC *dc,CPoint newPoint)
{
		setMfoundShape(tryToSelect(newPoint));
		m_fPoint.SetPoint(newPoint.x,newPoint.y);
		getMfoundShape()->Paint(dc);
		setIsSelected(true);
		getMfoundShape()->Paint(dc);
		setIsSelected(true);

}
void Mover::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	setIsSelected(false);
}
void Mover::MouseOver(CDC *dc,CPoint newPoint)
{
	if(getIsSelected())
	{
		int maxX=0;
		int minX=0;
		int maxY=0;
		int minY=0;

		maxX= max(getSelectedShape()->getStartX(),getSelectedShape()->getEndX());
		minX= min(getSelectedShape()->getStartX(),getSelectedShape()->getEndX());
		maxY= max( getSelectedShape()->getStartY(),getSelectedShape()->getEndY());
		minY=  min(getSelectedShape()->getStartY(),getSelectedShape()->getEndY());
		int deltaX= (newPoint.x- getFpoint()->x);
		int deltaY= (newPoint.y- getFpoint()->y);
		
		getMfoundShape()->setIsSelected(false);

		getMfoundShape()->Paint(dc);
		
		
		
		
		
		
		
		
		
		if((minX<135 && deltaX<0) || (maxX>755 && deltaX>0))
		{
			
		}
		else
		{
			getMfoundShape()->setStartX(getMfoundShape()->getStartX()+deltaX);
			getMfoundShape()->setEndX(getMfoundShape()->getEndX()+deltaX);
		}
		if((minY<10 && deltaY<0) || (maxY>405 && deltaY>0))
		{
			
		}
		else
		{
			getMfoundShape()->setStartY(getMfoundShape()->getStartY()+deltaY);
			getMfoundShape()->setEndY(getMfoundShape()->getEndY()+deltaY);
		}

		getMfoundShape()->Paint(dc);

		getFpoint()->SetPoint(newPoint.x,newPoint.y);
	}



}