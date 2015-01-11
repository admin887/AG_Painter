#include "stdafx.h"
#include "Tool.h"
#include "ShapesGarage.h"
#pragma once
class Drawer: public Tool
{
private:
		bool isPressed;
public:
		Drawer(ShapesGarage &SG);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void DoubleClick(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);
};