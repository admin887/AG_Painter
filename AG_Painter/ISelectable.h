#include "stdafx.h"
class ISelectable
{
private:
	bool isSelected;
public:
	virtual bool getIsSelected()=0;
	virtual void setIsSelected(bool)=0 ;
};