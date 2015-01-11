#include "stdafx.h"
#include "ISelectable.h"
#include "Colorable.h"
#include "IWeightable.h"
#pragma once;

class Shape : public ISelectable, public IColorable, public IWeightable
{
private:
	int m_startX;
	int m_startY;
	int m_endX;
	int m_endY;

public:
	virtual void Paint(CDC *dc)=0 ;
	bool getIsSelected();
	void setIsSelected(bool) ;
	COLORREF getColorInside();
	COLORREF getColorOutside();
	void setColorInside(COLORREF);
	void setColorOutside(COLORREF);
	int getWeight();
	void setWeight(int);

	int getStartX();
	void setStartX(int newStartX);
	int getStartY();
	void setStartY(int newStartY);
	
	int getEndX();
	void setEndX(int newEndX);
	int getEndY();
	void setEndY(int newEndY);

};
enum ENUM_SHAPES {E_NULLSHAPE,E_POINT, E_ELIPSE, E_RECTANGLE, E_LINE};