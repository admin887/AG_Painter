#include "stdafx.h"
#include "selector.h"
#pragma once
class Mover: public selector
{
	protected:
		//bool m_isPressed;
		Shape* m_FoundedShape;
		CPoint m_fPoint;
	public:
		/*	bool isfirstClicked;*/		
		Mover(ShapesGarage &);
		Mover(Mover &);
		Shape* getMfoundShape();
		void setMfoundShape(Shape *);
		CPoint* getFpoint();
		void setFpoint(CPoint);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void DoubleClick(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);

};
