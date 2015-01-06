#include "stdafx.h"
#include "IAction.h"
#pragma once
class Tool: public IAction
{
	private:
		Shape *SelectedShape;
	public:
		virtual void MouseDown()=0;
		virtual void MouseUp()=0;
		virtual void DoubleClick()=0;
		Shape* getSelectedShape();
		void setSelectedShape(Shape *); 
};