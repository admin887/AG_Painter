#include "stdafx.h"
#include "Point.h"
#pragma once
class IAction
{
	public:
		virtual void MouseDown(CDC,Point);
		virtual void MouseUp(CDC,Point);
		virtual void DoubleClick(CDC,Point);
};