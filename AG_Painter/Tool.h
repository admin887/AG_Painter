#include "stdafx.h"
#include "IAction.h"
#pragma once
class Tool: public IAction
{
	private:
		Shape *SelectedShape;
	public:
		virtual void MouseDown();
		virtual void MouseUp();
		virtual void DoubleClick();
		Shape* getSelectedShape();
		void setSelectedShape(Shape *); 
};