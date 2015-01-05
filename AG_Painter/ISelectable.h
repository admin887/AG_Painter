#include "stdafx.h"
class ISelectable
{
protected:
	bool m_isSelected;
public:
	bool getIsSelected();
	void setIsSelected(bool) ;
};