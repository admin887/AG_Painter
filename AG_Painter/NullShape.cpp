#include "stdafx.h"
#include "NullShape.h"

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
NullShape::~NullShape(void)
{
	
}

void NullShape::Paint(CDC *dc)
{

}

