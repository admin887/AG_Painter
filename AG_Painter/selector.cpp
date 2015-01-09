#include "stdafx.h"
#include "selector.h"
#include "NullShape.h"
#include <algorithm>
#include <iterator>
#pragma once
selector::selector(ShapesGarage* newShapeGarage)
{
	shapeGarage=newShapeGarage;
}
Shape* selector::tryToSelect(POINT p)
{
	list<Shape*>::iterator i;
	for(i=shapeGarage->getAliveShapes()->begin();i!=shapeGarage->getAliveShapes()->begin();i++)
		if((p.x<i._Mynode()->_Myval->getEndX())&&(p.y<i._Mynode()->_Myval->getEndY())&&((p.x>i._Mynode()->_Myval->getEndY())&&(p.y>i._Mynode()->_Myval->getStartY())))
		{
			i._Mynode()->_Myval->setIsSelected(true);
			return i._Mynode()->_Myval;
		}
		else
			return new NullShape();
}