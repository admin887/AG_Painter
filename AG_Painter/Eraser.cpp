#include "stdafx.h"
#include "selector.h"
#include "NullShape.h"
#include <algorithm>
#include <iterator>
#include "Eraser.h"
#pragma once
Eraser::Eraser(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
	setIsSelected(false);
}
Eraser::Eraser(Eraser &newMover)
{
	setShapeGarage(*newMover.getShapeGarage());
	setIsSelected(newMover.getIsSelected());
}
Eraser &Eraser::operator=(Eraser &newMover)
{
	setShapeGarage(*newMover.getShapeGarage());
	setIsSelected(newMover.getIsSelected());
	return *this;
}
Shape* Eraser::getMfoundShape()
{
	return m_FoundedShape;
}
void Eraser::setMfoundShape(Shape* newMfoundShape)
{
	m_FoundedShape=newMfoundShape;
}
CPoint* Eraser::getFpoint()
{
	return &m_fPoint;
}
void Eraser::setFpoint(CPoint newFpoint)
{
	m_fPoint=newFpoint;
}
void Eraser::MouseDown(CDC *dc,CPoint newPoint)
{
		setMfoundShape(tryToSelect(newPoint));
		m_fPoint.SetPoint(newPoint.x,newPoint.y);
		getMfoundShape()->Paint(dc);
		setIsSelected(true);
		getMfoundShape()->Paint(dc);
		setIsSelected(true);

		m_FoundedShape->setStartX(0);
		m_FoundedShape->setStartY(0);
		m_FoundedShape->setEndX(0);
		m_FoundedShape->setEndY(0);
		m_FoundedShape->setWeight(0);
		m_FoundedShape->setColorInside(0);
		m_FoundedShape->setColorOutside(0);


}
void Eraser::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	setIsSelected(false);
		m_FoundedShape->setIsSelected(false);
}
void Eraser::DoubleClick(CDC *dc,CPoint newPoint)
{
	

}
void Eraser::MouseOver(CDC *dc,CPoint newPoint)
{

}