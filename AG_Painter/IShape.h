#include "stdafx.h"
#include "ISelectable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class Shape : public ISelectable
{
public:
	virtual void Paint(CDC *dc)=0 ;
	virtual bool getIsSelected()=0;
	virtual void setIsSelected(bool)=0 ;


};