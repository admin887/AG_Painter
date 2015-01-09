#include "stdafx.h"
#include "Tool.h"
#include "ShapesGarage.h"
#pragma once
class selector: public Tool
{
	public:
		selector(ShapesGarage &SG);
		Shape* tryToSelect(CPoint);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void DoubleClick(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);
};