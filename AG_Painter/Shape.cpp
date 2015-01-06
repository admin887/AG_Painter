#include "stdafx.h"
#include "Shape.h"
	bool Shape::getIsSelected()
	{
		return m_isSelected;
	}
	void Shape::setIsSelected(bool newIsSelected) 
	{
		m_isSelected= newIsSelected;
	}
	COLORREF  Shape::getColorInside()
	{
		return m_inSideColor;
	}
	COLORREF  Shape::getColorOutside()
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
	int Shape::getWeight()
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

	int Shape::getStartX()
	{
		return m_startX;
	}
	void Shape::setStartX(int newStartX)
	{
		m_startX= newStartX;
	}
	int Shape::getStartY()
	{
		return m_startY;
	}
	void Shape::setStartY(int newStartY)
	{
		m_startY= newStartY;
	}
	
	int Shape::getEndX()
	{
		return m_endX;
	}
	void Shape::setEndX(int newEndX)
	{
		m_endX= newEndX;
	}
	int Shape::getEndY()
	{
		return m_endY;
	}
	void Shape::setEndY(int newEndY)
	{
		m_endY= newEndY;
	}