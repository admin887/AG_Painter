#include "stdafx.h"
#include "Tool.h"
#pragma once
class ToolNull: public Tool
{
public:
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);
};