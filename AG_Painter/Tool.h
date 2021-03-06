#include "stdafx.h"
#include "IAction.h"
#include "ShapesGarage.h"
#pragma once
class Tool: public IAction, public ISelectable
{
	private:
		Shape *SelectedShape;
		ShapesGarage *sg;
	public:
		virtual void MouseDown(CDC *dc,CPoint)=0;
		virtual void MouseUp(CDC *dc,CPoint)=0;
		virtual void MouseOver(CDC *dc,CPoint)=0;
		Shape* getSelectedShape();
		void setSelectedShape(Shape *); 
		ShapesGarage* getShapeGarage();
		void setShapeGarage(ShapesGarage &newSG);
		bool getIsSelected() const;
		void setIsSelected(bool newIsSelected) ;
};