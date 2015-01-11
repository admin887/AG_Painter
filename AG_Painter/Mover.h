#include "stdafx.h"
#include "selector.h"
#pragma once
class Mover: public selector
{
	public:
		/*	bool isfirstClicked;*/
		bool isPressed;
		Shape* FoundedShape;
		CPoint fPoint;
		Mover(ShapesGarage &SG);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void DoubleClick(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);

};
