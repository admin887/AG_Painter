#include "stdafx.h"
#include "UndoRedo.h"
using namespace std;
#include <algorithm>
#pragma once
UndoRedo::UndoRedo()
{
	
}
UndoRedo::UndoRedo(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
	setIsSelected(false);
}
UndoRedo &UndoRedo::operator=(UndoRedo newDrawer)
{
	return newDrawer;
}
UndoRedo::UndoRedo(UndoRedo &d)
{
	this->setSelectedShape(d.getSelectedShape());
}
UndoRedo::~UndoRedo(void)
{

}
void UndoRedo::MouseDown(CDC *dc,CPoint newPoint)
{


}
void UndoRedo::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{

}
void UndoRedo::DoubleClick(CDC *dc,CPoint newPoint)
{

}
void UndoRedo::MouseOver(CDC *dc,CPoint newPoint)
{

}
void UndoRedo::Undo()
{
	if(getShapeGarage()->getAliveShapes()->size()==0)
	{
		return;
	}

	std::list<Shape*>::iterator LastShape;
	LastShape =getShapeGarage()->getAliveShapes()->begin();
	Shape *myShape=	LastShape._Mynode()->_Myval;
	getShapeGarage()->getRetiredShapes()->push_front(myShape);
	getShapeGarage()->getAliveShapes()->remove(myShape);
}
void UndoRedo::Redo()
{

	if(getShapeGarage()->getRetiredShapes()->size()==0)
	{
		return;
	}

	std::list<Shape*>::iterator LastShape;
	LastShape =getShapeGarage()->getRetiredShapes()->begin();
	Shape *myShape=	LastShape._Mynode()->_Myval;
	getShapeGarage()->getAliveShapes()->push_front(myShape);
	getShapeGarage()->getRetiredShapes()->remove(myShape);

}

