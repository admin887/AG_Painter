#include "stdafx.h"
#include "Tool.h"
Shape* Tool::getSelectedShape()
{
	return SelectedShape;
}
void Tool::setSelectedShape(Shape* newShape)
{
	SelectedShape=newShape;
}