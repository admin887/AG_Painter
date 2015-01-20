#include "stdafx.h"
#include "selector.h"
#pragma once
class Eraser: public selector
{
	protected:
		Shape* m_FoundedShape;
		CPoint m_fPoint;
	public:
		/*	bool isfirstClicked;*/		
		Eraser(ShapesGarage &);
		Eraser(Eraser &);
		virtual ~Eraser() {};
		Eraser &operator=( Eraser &);
		Shape* getMfoundShape();
		void setMfoundShape(Shape *);
		CPoint* getFpoint();
		void setFpoint(CPoint);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);

};
