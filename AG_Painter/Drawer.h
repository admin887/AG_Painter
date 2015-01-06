#include "stdafx.h"
#include "Tool.h"
#pragma once
class Drawer: public Tool
{
	virtual void MouseDown(CDC*,Point);
	virtual void MouseUp(CDC*,Point);
	virtual void DoubleClick(CDC*,Point);
};