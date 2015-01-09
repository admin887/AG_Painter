#include "stdafx.h"
#include "Drawer.h"

Drawer::Drawer(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
}
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

}
void Drawer::DoubleClick(CDC *dc,CPoint newPoint)
{

	/*getSelectedShape()->setStartX(newPoint.x);
	getSelectedShape()->setStartY(newPoint.y);
	getSelectedShape()->Paint(dc);*/
}
void Drawer::MouseOver(CDC *dc,CPoint newPoint)
{
	if(!(getSelectedShape()->getEndX()==0) && !(getSelectedShape()->getEndY()==0))
	{
		getSelectedShape()->Paint(dc);
	}
	if((getSelectedShape()->getEndX()==-1) && (getSelectedShape()->getEndY()==-1))
	{
		getSelectedShape()->Paint(dc);
		getSelectedShape()->setStartX(newPoint.x);
		getSelectedShape()->setStartY(newPoint.y);
		getSelectedShape()->Paint(dc);
	}
	else
	{
	getSelectedShape()->setEndX(newPoint.x);
	getSelectedShape()->setEndY(newPoint.y);
	getSelectedShape()->Paint(dc);
	}
}

