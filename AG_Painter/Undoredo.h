#include "stdafx.h"
#include "Tool.h"
#include "ShapesGarage.h"
#pragma once
class UndoRedo: public Tool
{
private:
		//bool m_isPressed;
public:
		UndoRedo();
		UndoRedo(ShapesGarage &SG);
		UndoRedo &operator=(UndoRedo);
		UndoRedo(UndoRedo &d);
		~UndoRedo(void);
		virtual void MouseDown(CDC *dc,CPoint);
		virtual void MouseUp(CDC *dc,CPoint);
		virtual void DoubleClick(CDC *dc,CPoint);
		virtual void MouseOver(CDC *dc,CPoint);

		void Undo();
		void Redo();
};