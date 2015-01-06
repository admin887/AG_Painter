#include "stdafx.h"
#include "Shape.h"
#pragma once
class IAction
{
	public:
		virtual void MouseDown(CDC,CPoint);
		virtual void MouseUp(CDC,CPoint);
		virtual void DoubleClick(CDC,CPoint);
};