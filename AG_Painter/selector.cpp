#include "stdafx.h"
#include "selector.h"
#include "NullShape.h"
#include <algorithm>
#include <iterator>
#pragma once
selector::selector()
{
	
}
selector::selector(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
}
selector::~selector()
{
}
selector &selector::operator=(selector &newSelector)
{
	setShapeGarage(*newSelector.getShapeGarage());
	return *this;
}
Shape* selector::tryToSelect(CPoint p)
{
	std::list<Shape*>::iterator i;
	Shape* FoundedShape= new NullShape();
	bool found=false;

	int maxX=0;
	int minX=0;
	int maxY=0;
	int minY=0;

	maxX= max(getSelectedShape()->getStartX(),getSelectedShape()->getEndX());
	minX= min(getSelectedShape()->getStartX(),getSelectedShape()->getEndX());
	maxY= max( getSelectedShape()->getStartY(),getSelectedShape()->getEndY());
	minY=  min(getSelectedShape()->getStartY(),getSelectedShape()->getEndY());





	for (i =getShapeGarage()->getAliveShapes()->begin() ; i!=getShapeGarage()->getAliveShapes()->end() ; i++)
	{
			maxX=0;
			minX=0;
			maxY=0;
			minY=0;

			maxX= max(i._Mynode()->_Myval->getStartX(),i._Mynode()->_Myval->getEndX());
			minX= min(i._Mynode()->_Myval->getStartX(),i._Mynode()->_Myval->getEndX());
			maxY= max( i._Mynode()->_Myval->getStartY(),i._Mynode()->_Myval->getEndY());
			minY=  min(i._Mynode()->_Myval->getStartY(),i._Mynode()->_Myval->getEndY());







		if((p.x<3+maxX)&&
		   (p.y<3+maxY)
			&&
			((p.x>minX-3)&&
		(p.y>minY-3) && !found))
		{
			i._Mynode()->_Myval->setIsSelected(true);
			delete(FoundedShape);
			FoundedShape= i._Mynode()->_Myval;
			found=true;
		}
		else
		{
			i._Mynode()->_Myval->setIsSelected(false);
		}
	}
	return FoundedShape;


}
void selector::MouseDown(CDC *dc,CPoint newPoint)
{
	Shape* s= 	tryToSelect(newPoint);
}
void selector::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{

}
void selector::MouseOver(CDC *dc,CPoint newPoint)
{

}