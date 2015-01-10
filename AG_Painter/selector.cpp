#include "stdafx.h"
#include "selector.h"
#include "NullShape.h"
#include <algorithm>
#include <iterator>
#pragma once
selector::selector(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
}
Shape* selector::tryToSelect(CPoint p)
{
	std::list<Shape*>::iterator i;
	Shape* FoundedShape= new NullShape();
	bool found=false;


	for (i =getShapeGarage()->getAliveShapes()->begin() ; i!=getShapeGarage()->getAliveShapes()->end() ; i++)
	{
		if((p.x<i._Mynode()->_Myval->getEndX())&&
		   (p.y<i._Mynode()->_Myval->getEndY())
			&&
			((p.x>i._Mynode()->_Myval->getStartX())&&
		(p.y>i._Mynode()->_Myval->getStartY())) && !found)
		{
			i._Mynode()->_Myval->setIsSelected(false);
			//return i._Mynode()->_Myval;
			delete(FoundedShape);
			FoundedShape= i._Mynode()->_Myval;
			found=true;
		}
		else
		{
			i._Mynode()->_Myval->setIsSelected(true);
		}
	}
	return new NullShape();


}
void selector::MouseDown(CDC *dc,CPoint newPoint)
{
	Shape* s= 	tryToSelect(newPoint);

	//s->setEndX(s->getEndX()+100);
	
}
void selector::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{

}
void selector::DoubleClick(CDC *dc,CPoint newPoint)
{
	

}
void selector::MouseOver(CDC *dc,CPoint newPoint)
{

}