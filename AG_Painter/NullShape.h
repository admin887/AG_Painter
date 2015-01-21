#include "stdafx.h"
#include "Point.h"
#include <Windows.h>
#include <iostream>
#pragma once
class NullShape:public Shape
{
	DECLARE_SERIAL (NullShape)
	public:
		NullShape();
		NullShape(NullShape &);
		NullShape &operator=(const NullShape &);
		virtual ~NullShape();//destructor
		void Paint(CDC *dc);

};