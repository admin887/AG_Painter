#include "stdafx.h"
#pragma once
class ISelectable
{
protected:
	bool m_isSelected;
public:
	bool getIsSelected() const;
	void setIsSelected(bool) ;
};