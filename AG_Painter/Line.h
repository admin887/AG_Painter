#include "stdafx.h"
#include "Point.h"
#pragma once
	
class Line:public Shape
{
	DECLARE_SERIAL (Line)
private:
public:
	Line(Point newStart, Point newEnd, int newWeight, COLORREF newColor);
	Line(int=0, int=0, int=0,int= 0,int newWeight=1, COLORREF newColor=0);
	Line(Line &l);
	virtual ~Line(void);
	
	Line &operator=(const Line &);
	void Paint(CDC *dc);
};