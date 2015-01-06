#include "stdafx.h"
#include "Tool.h"
#pragma once
class Drawer: public Tool
{
	virtual void MouseDown(CDC*,CPoint);
	virtual void MouseUp(CDC*,CPoint);
	virtual void DoubleClick(CDC*,CPoint);
};