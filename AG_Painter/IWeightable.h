#include "stdafx.h"
#pragma once
class IWeightable
{
protected:
	int m_weight;
public:
	int getWeight() const;
	void setWeight(int) ;
};