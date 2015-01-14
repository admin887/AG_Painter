#include "stdafx.h"
#include "NullShape.h"
#pragma once

NullShape::NullShape()
{
	setStartX(0);
	setStartY(0);
	setEndY(-1);
	setEndX(-1);
	setIsSelected(false);
	setColorInside(0);
	setColorOutside(0);
	setWeight(0);
}
NullShape::NullShape(NullShape &newNullShape)
{
	setStartX(newNullShape.getStartX());
	setStartY(newNullShape.getStartY());
	setEndX(newNullShape.getEndX());
	setEndY(newNullShape.getEndY());
	setIsSelected(newNullShape.getIsSelected());
	setColorInside(newNullShape.getColorInside());
	setColorOutside(newNullShape.getColorOutside());
	setWeight(newNullShape.getWeight());
}
NullShape &NullShape::operator=(NullShape &newNullShape)
{
	setStartX(newNullShape.getStartX());
	setStartY(newNullShape.getStartY());
	setEndX(newNullShape.getEndX());
	setEndY(newNullShape.getEndY());
	setIsSelected(newNullShape.getIsSelected());
	setColorInside(newNullShape.getColorInside());
	setColorOutside(newNullShape.getColorOutside());
	setWeight(newNullShape.getWeight());
	return *this;
}
NullShape::~NullShape(void)
{
	
}

void NullShape::Paint(CDC *dc)
{

}

