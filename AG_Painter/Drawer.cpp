#include "stdafx.h"
#include "Drawer.h"
using namespace std;
#include <algorithm>
#pragma once
Drawer::Drawer()
{
	
}
Drawer::Drawer(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
	setIsSelected(false);
}
Drawer &Drawer::operator=(Drawer newDrawer)
{
	return newDrawer;
}
Drawer::Drawer(Drawer &d)
{
	this->setSelectedShape(d.getSelectedShape());
}
Drawer::~Drawer(void)
{

}
void Drawer::MouseDown(CDC *dc,CPoint newPoint)
{
	Shape *myshape=   getShapeGarage()->CreateShape(getShapeGarage()->getTypeToConstract());
			if(!(myshape->getEndX()==-1) && !(myshape->getEndY()==-1))
			{
				myshape->setEndX(128);
				myshape->setEndY(0);	
			}
				if(newPoint.x<128)
					newPoint.x=128;
				myshape->setStartX(newPoint.x);
				myshape->setStartY(newPoint.y);
		setIsSelected(true);

		myshape->setColorInside(getShapeGarage()->getCurrFill());
		myshape->setColorOutside(getShapeGarage()->getcurrLine());
		myshape->setWeight(getShapeGarage()->getCurrWeight());

		


	
	if(getShapeGarage()->getRetiredShapes()->size()==0)
	{
		return;
	}

	getShapeGarage()->DeleteRetired();

}
void Drawer::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	setIsSelected(false);
}
void Drawer::MouseOver(CDC *dc,CPoint newPoint)
{
	if(!getIsSelected())
	{
		return;
	}

	if(!(getSelectedShape()->getEndX()==0) && !(getSelectedShape()->getEndY()==0)) // this is NULL PRT!
	{
		getSelectedShape()->Paint(dc);
	}
	if(((getSelectedShape()->getEndX()==getSelectedShape()->getStartX()) && (getSelectedShape()->getEndY()==getSelectedShape()->getStartY())) || ((getSelectedShape()->getEndX()==-1) && (getSelectedShape()->getEndY()==-1))) //this is Point !!
	{
		getSelectedShape()->Paint(dc);
		getSelectedShape()->setStartX(newPoint.x);
		getSelectedShape()->setStartY(newPoint.y);
		getSelectedShape()->setEndX(newPoint.x);
		getSelectedShape()->setEndY(newPoint.y);
		getSelectedShape()->Paint(dc);

		Shape *myshape=   getShapeGarage()->CreateShape(getShapeGarage()->getTypeToConstract());
			if(newPoint.x<128)
				newPoint.x=128;	
			myshape->setStartX(newPoint.x);
			myshape->setStartY(newPoint.y);
			myshape->setEndX(newPoint.x);
			myshape->setEndY(newPoint.y);
			myshape->setColorInside(getShapeGarage()->getCurrFill());
			myshape->setColorOutside(getShapeGarage()->getcurrLine());
			myshape->setWeight(getShapeGarage()->getCurrWeight());
			myshape->Paint(dc);
	}
	else
	{
	if(newPoint.x<128)
		newPoint.x=128;
	getSelectedShape()->setEndX(newPoint.x);
	getSelectedShape()->setEndY(newPoint.y);
	getSelectedShape()->Paint(dc);
	}
}

