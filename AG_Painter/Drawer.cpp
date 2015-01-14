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
		m_isPressed= false;
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
				myshape->setEndX(0);
				myshape->setEndY(0);	
			}
			myshape->setStartX(newPoint.x);
				myshape->setStartY(newPoint.y);
		m_isPressed=true;

		myshape->setColorInside(getShapeGarage()->getCurrFill());
		myshape->setColorOutside(getShapeGarage()->getcurrLine());

}
void Drawer::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{
	int maxX=0;
	int minX=0;
	int maxY=0;
	int minY=0;

	maxX= max(getSelectedShape()->getStartX(),getSelectedShape()->getEndX());
	minX= min(getSelectedShape()->getStartX(),getSelectedShape()->getEndX());
	maxY= max( getSelectedShape()->getStartY(),getSelectedShape()->getEndY());
	minY=  min(getSelectedShape()->getStartY(),getSelectedShape()->getEndY());

	getSelectedShape()->setEndX(maxX);
	getSelectedShape()->setEndY(maxY);
	getSelectedShape()->setStartX(minX);
	getSelectedShape()->setStartY(minY);


	m_isPressed=false;
}
void Drawer::DoubleClick(CDC *dc,CPoint newPoint)
{

}
void Drawer::MouseOver(CDC *dc,CPoint newPoint)
{
	if(!m_isPressed)
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

	getSelectedShape()->setEndX(newPoint.x);
	getSelectedShape()->setEndY(newPoint.y);
	getSelectedShape()->Paint(dc);
	}
}

