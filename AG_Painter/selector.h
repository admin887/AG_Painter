#include "stdafx.h"
#include "Tool.h"
#include "ShapesGarage.h"
#pragma once
class selector: public Tool
{
	private:
		ShapesGarage *shapeGarage;
	public:
		selector(ShapesGarage* =nullptr);
		Shape* tryToSelect(POINT);
};