#include "stdafx.h"
#include "selector.h"
#include "NullShape.h"
#include <algorithm>
#include <iterator>
#include "Mover.h"
#pragma once
Mover::Mover(ShapesGarage &newSG)
{
	setShapeGarage(newSG);
	isPressed=false;
}

void Mover::MouseDown(CDC *dc,CPoint newPoint)
{
		FoundedShape= 	tryToSelect(newPoint);
		fPoint.SetPoint(newPoint.x,newPoint.y);
		FoundedShape->Paint(dc);
		isPressed= true;
		FoundedShape->Paint(dc);
			isPressed=true;
}
void Mover::MouseUp(CDC *dc,CPoint newPoint) // need to change to MouseOver
{

	isPressed= false;
}
void Mover::DoubleClick(CDC *dc,CPoint newPoint)
{
	

}
void Mover::MouseOver(CDC *dc,CPoint newPoint)
{

	if(isPressed)
	{
		int deltaX= (newPoint.x- fPoint.x);
		int deltaY= (newPoint.y- fPoint.y);

		FoundedShape->setIsSelected(false);

			FoundedShape->Paint(dc);

		FoundedShape->setStartX(FoundedShape->getStartX()+deltaX);
		FoundedShape->setStartY(FoundedShape->getStartY()+deltaY);

		FoundedShape->setEndX(FoundedShape->getEndX()+deltaX);
		FoundedShape->setEndY(FoundedShape->getEndY()+deltaY);

		FoundedShape->Paint(dc);

		fPoint.SetPoint(newPoint.x,newPoint.y);

	}



}