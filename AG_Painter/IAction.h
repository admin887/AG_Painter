#include "stdafx.h"
#include "Point.h"
#pragma once
class IAction
{
	public:
		virtual void MouseDown(CDC,Point)=0;
		virtual void MouseUp(CDC,Point)=0;
		virtual void DoubleClick(CDC,Point)=0;
};