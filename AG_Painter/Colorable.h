#include "stdafx.h"
#include <Windows.h>

class IColorable
{
protected:
	COLORREF m_inSideColor;
	COLORREF m_OutsideColor;
public:
	COLORREF getColorInside() const;
	COLORREF getColorOutside() const;
	void setColorInside(COLORREF);
	void setColorOutside(COLORREF);
};