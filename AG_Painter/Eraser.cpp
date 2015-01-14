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
		delete m_FoundedShape;
		m_FoundedShape= new NullShape();
}
void Eraser::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	setIsSelected(false);
}
void Eraser::DoubleClick(CDC *dc,CPoint newPoint)
{
	

}
void Eraser::MouseOver(CDC *dc,CPoint newPoint)
{

}