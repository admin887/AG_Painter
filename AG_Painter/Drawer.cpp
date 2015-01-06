#include "stdafx.h"
#include "Drawer.h"

void Drawer::MouseDown(CDC *dc,Point newPoint)
{
	getSelectedShape()->setStartX(newPoint.getStartX());
	getSelectedShape()->setStartY(newPoint.getStartY());
	getSelectedShape()->Paint(dc);
}
void Drawer::MouseUp(CDC *dc,Point newPoint)
{
	getSelectedShape()->setStartX(newPoint.getStartX());
	getSelectedShape()->setStartY(newPoint.getStartY());
	getSelectedShape()->Paint(dc);
}
void Drawer::DoubleClick(CDC *dc,Point newPoint)
{
	getSelectedShape()->setStartX(newPoint.getStartX());
	getSelectedShape()->setStartY(newPoint.getStartY());
	getSelectedShape()->Paint(dc);
}