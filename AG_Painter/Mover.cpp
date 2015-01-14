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
void Mover::DoubleClick(CDC *dc,CPoint newPoint)
{
	

}
void Mover::MouseOver(CDC *dc,CPoint newPoint)
{

	if(getIsSelected())
	{
		int deltaX= (newPoint.x- getFpoint()->x);
		int deltaY= (newPoint.y- getFpoint()->y);

		getMfoundShape()->setIsSelected(false);

		getMfoundShape()->Paint(dc);

		getMfoundShape()->setStartX(getMfoundShape()->getStartX()+deltaX);
		getMfoundShape()->setStartY(getMfoundShape()->getStartY()+deltaY);

		getMfoundShape()->setEndX(getMfoundShape()->getEndX()+deltaX);
		getMfoundShape()->setEndY(getMfoundShape()->getEndY()+deltaY);

		getMfoundShape()->Paint(dc);

		getFpoint()->SetPoint(newPoint.x,newPoint.y);
	}



}