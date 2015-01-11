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