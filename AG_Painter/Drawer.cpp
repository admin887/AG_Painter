#include "stdafx.h"
#include "Drawer.h"
#pragma once

Drawer::Drawer(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
		isPressed= false;
}
void Drawer::MouseDown(CDC *dc,CPoint newPoint)
{
	Shape *myshape=   getShapeGarage()->CreateShape(getShapeGarage()->getTypeToConstract());
			if(!(myshape->getEndX()==-1) && !(myshape->getEndY()==-1))
			{
				myshape->setEndX(0);
				myshape->setEndY(0);	
			}
			myshape->setStartX(newPoint.x);
				myshape->setStartY(newPoint.y);
		isPressed=true;

		myshape->setColorInside(getShapeGarage()->getCurrFill());
		myshape->setColorOutside(getShapeGarage()->getcurrLine());

}
void Drawer::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	isPressed=false;
}
void Drawer::DoubleClick(CDC *dc,CPoint newPoint)
{

}
void Drawer::MouseOver(CDC *dc,CPoint newPoint)
{
	if(!isPressed)
	{
		return;
	}

	if(!(getSelectedShape()->getEndX()==0) && !(getSelectedShape()->getEndY()==0))
	{
		getSelectedShape()->Paint(dc);
	}
	if((getSelectedShape()->getEndX()==-1) && (getSelectedShape()->getEndY()==-1)) //this is Point !!
	{
		getSelectedShape()->Paint(dc);
		getSelectedShape()->setStartX(newPoint.x);
		getSelectedShape()->setStartY(newPoint.y);
		getSelectedShape()->Paint(dc);

		Shape *myshape=   getShapeGarage()->CreateShape(getShapeGarage()->getTypeToConstract());
	
			myshape->setStartX(newPoint.x);
			myshape->setStartY(newPoint.y);
	}
	else
	{
	getSelectedShape()->setEndX(newPoint.x);
	getSelectedShape()->setEndY(newPoint.y);
	getSelectedShape()->Paint(dc);
	}
}

