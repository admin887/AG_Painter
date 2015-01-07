#include "stdafx.h"
#include "Drawer.h"

void Drawer::MouseDown(CDC *dc,CPoint newPoint)
{
	getSelectedShape()->setStartX(newPoint.x);
	getSelectedShape()->setStartY(newPoint.y);

	if(getSelectedShape()->getEndX()== -1)
	{
		getSelectedShape()->Paint(dc);
	}
	
}
void Drawer::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{

	getSelectedShape()->setEndX(newPoint.x);
	getSelectedShape()->setEndY(newPoint.y);
	getSelectedShape()->Paint(dc);
}
void Drawer::DoubleClick(CDC *dc,CPoint newPoint)
{
	getSelectedShape()->setStartX(newPoint.x);
	getSelectedShape()->setStartY(newPoint.y);
	getSelectedShape()->Paint(dc);
}