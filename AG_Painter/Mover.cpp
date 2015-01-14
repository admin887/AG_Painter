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
	m_isPressed=false;
}
void Mover::MouseDown(CDC *dc,CPoint newPoint)
{
		m_FoundedShape= 	tryToSelect(newPoint);
		m_fPoint.SetPoint(newPoint.x,newPoint.y);
		m_FoundedShape->Paint(dc);
		m_isPressed= true;
		m_FoundedShape->Paint(dc);
		m_isPressed=true;
}
void Mover::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{

	m_isPressed= false;
}
void Mover::DoubleClick(CDC *dc,CPoint newPoint)
{
	

}
void Mover::MouseOver(CDC *dc,CPoint newPoint)
{

	if(m_isPressed)
	{
		int deltaX= (newPoint.x- m_fPoint.x);
		int deltaY= (newPoint.y- m_fPoint.y);

		m_FoundedShape->setIsSelected(false);

		m_FoundedShape->Paint(dc);

		m_FoundedShape->setStartX(m_FoundedShape->getStartX()+deltaX);
		m_FoundedShape->setStartY(m_FoundedShape->getStartY()+deltaY);

		m_FoundedShape->setEndX(m_FoundedShape->getEndX()+deltaX);
		m_FoundedShape->setEndY(m_FoundedShape->getEndY()+deltaY);

		m_FoundedShape->Paint(dc);

		m_fPoint.SetPoint(newPoint.x,newPoint.y);

	}



}