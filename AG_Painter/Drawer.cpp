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
	//this->setShapeGarage(d.getShapeGarage());

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
				myshape->setStartX(128);
			else
				myshape->setStartX(newPoint.x);
				myshape->setStartY(newPoint.y);
		setIsSelected(true);

		myshape->setColorInside(getShapeGarage()->getCurrFill());
		myshape->setColorOutside(getShapeGarage()->getcurrLine());

}
void Drawer::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	setIsSelected(false);
}
void Drawer::DoubleClick(CDC *dc,CPoint newPoint)
{

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
	if(newPoint.x<128)
		getSelectedShape()->setEndX(128);
	else
		getSelectedShape()->setEndX(newPoint.x);
	getSelectedShape()->setEndY(newPoint.y);
	getSelectedShape()->Paint(dc);
	}
}

