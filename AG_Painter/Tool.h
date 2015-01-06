#include "stdafx.h"
#include "IAction.h"
#pragma once
class Tool: public IAction
{
	private:
		Shape *SelectedShape;
	public:
		virtual void MouseDown(CDC *dc,CPoint)=0;
		virtual void MouseUp(CDC *dc,CPoint)=0;
		virtual void DoubleClick(CDC *dc,CPoint)=0;
		Shape* getSelectedShape();
		void setSelectedShape(Shape *); 
};