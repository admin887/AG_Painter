#include "stdafx.h"
#include "Shape.h"
#pragma once

IMPLEMENT_SERIAL (Shape, CObject, 1)

	bool Shape::getIsSelected() const
	{
		return m_isSelected;
	}
	void Shape::setIsSelected(bool newIsSelected) 
	{
		m_isSelected= newIsSelected;
	}
	COLORREF  Shape::getColorInside() const
	{
		return m_inSideColor;
	}
	COLORREF  Shape::getColorOutside() const
	{
		return m_OutsideColor;
	}
	void  Shape::setColorInside(COLORREF newColorInside)
	{
		m_inSideColor= newColorInside;
	}
	void  Shape::setColorOutside(COLORREF newColorOutside)
	{
		m_OutsideColor= newColorOutside;
	}
	int Shape::getWeight() const
	{
		return m_weight;
	}
	void Shape::setWeight(int newWeight)
	{
		if(newWeight>=0)
		m_weight= newWeight;
	else
		m_weight=0;	
	}

	int Shape::getStartX() const
	{
		return m_startX;
	}
	void Shape::setStartX(int newStartX)
	{
			m_startX= newStartX;
	}
	int Shape::getStartY() const
	{
		return m_startY;
	}
	void Shape::setStartY(int newStartY)
	{
			m_startY= newStartY;
	}
	
	int Shape::getEndX() const
	{
		return m_endX;
	}
	void Shape::setEndX(int newEndX)
	{
		
			m_endX= newEndX;
	}
	int Shape::getEndY() const
	{
		return m_endY;
	}
	void Shape::setEndY(int newEndY)
	{
		
			m_endY= newEndY;
	}
	void Shape::Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar << m_startX;
			ar << m_endX;
			ar << m_startY;
			ar << m_endY;
			ar << m_inSideColor;
			ar << m_OutsideColor;
			ar << m_weight;
			//!!7 //ar << KIND;
		}
		else // Loading, not storing
		{
			ar >> m_startX;
			ar >> m_endX;
			ar >> m_startY;
			ar >> m_endY;
			ar >> m_inSideColor;
			ar >> m_OutsideColor;
			ar >> m_weight;
			//!!7 //ar >> KIND;
		}
	}