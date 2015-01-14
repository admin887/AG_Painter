#include "stdafx.h"
#include "Tool.h"
#pragma once

Shape* Tool::getSelectedShape()
{
	return SelectedShape;
}
void Tool::setSelectedShape(Shape* newShape)
{
	SelectedShape=newShape;
}

ShapesGarage* Tool::getShapeGarage()
{
	return sg;
}
void Tool::setShapeGarage(ShapesGarage &newSG)
{
	sg= &newSG;
}
bool Tool::getIsSelected()
	{
		return m_isSelected;
	}
	void Tool::setIsSelected(bool newIsSelected) 
	{
		m_isSelected= newIsSelected;
	}