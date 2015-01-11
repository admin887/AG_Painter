#include "stdafx.h"
#pragma once
class ISelectable
{
protected:
	bool m_isSelected;
public:
	bool getIsSelected();
	void setIsSelected(bool) ;
};