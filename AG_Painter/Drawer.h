#include "stdafx.h"
#include "Tool.h"
#include "ShapesGarage.h"
#pragma once
class Drawer: public Tool
{
private:
		//bool m_isPressed;
public:
		Drawer();
		Drawer(ShapesGarage &SG);
		Drawer &operator=(Drawer);
		Drawer(Drawer &d);
		~Drawer(void);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void DoubleClick(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);
};