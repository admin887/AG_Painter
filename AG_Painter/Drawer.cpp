#include "stdafx.h"
#include "Drawer.h"

void Drawer::MouseDown(CDC *dc,CPoint newPoint)
{
	getSelectedShape()->setStartX(newPoint.x);
	getSelectedShape()->setStartY(newPoint.y);
	getSelectedShape()->Paint(dc);
}
void Drawer::MouseUp(CDC *dc,CPoint newPoint)
{
	getSelectedShape()->setStartX(newPoint.x);
	getSelectedShape()->setStartY(newPoint.y);
	getSelectedShape()->Paint(dc);
}
void Drawer::DoubleClick(CDC *dc,CPoint newPoint)
{
	getSelectedShape()->setStartX(newPoint.x);
	getSelectedShape()->setStartY(newPoint.y);
	getSelectedShape()->Paint(dc);
}