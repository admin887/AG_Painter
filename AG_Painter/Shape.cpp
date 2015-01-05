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