#include "stdafx.h"
#include "ISelectable.h"
#include "Colorable.h"
#include "IWeightable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class Shape : public ISelectable, public IColorable, public IWeightable
{
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

};