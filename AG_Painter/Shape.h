#include "stdafx.h"
#include "ISelectable.h"
#include "Colorable.h"
#include "IWeightable.h"
#pragma once;

class Shape : public ISelectable, public IColorable, public IWeightable, public CObject
{
	DECLARE_SERIAL (Shape)

private:
	int m_startX;
	int m_startY;
	int m_endX;
	int m_endY;

public:
	Shape() {};
	void Serialize (CArchive& ar);
	virtual void Paint(CDC *dc){} ;
	bool getIsSelected() const;
	void setIsSelected(bool) ;
	COLORREF getColorInside() const;
	COLORREF getColorOutside() const;
	void setColorInside(COLORREF);
	void setColorOutside(COLORREF);
	int getWeight() const;
	void setWeight(int);

	int getStartX() const;
	void setStartX(int newStartX);
	int getStartY() const;
	void setStartY(int newStartY);
	
	int getEndX() const;
	void setEndX(int newEndX);
	int getEndY() const;
	void setEndY(int newEndY);
	virtual ~Shape() {};
};
enum ENUM_SHAPES {E_NULLSHAPE,E_POINT, E_ELIPSE, E_RECTANGLE, E_LINE};
