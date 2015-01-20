#include "stdafx.h"
#include "Shape.h"
#pragma once
class IAction
{
	public:
		virtual void MouseDown(CDC *dc,CPoint)=0;
		virtual void MouseUp(CDC *dc,CPoint)=0;
		virtual void MouseOver(CDC *dc,CPoint)=0;
};