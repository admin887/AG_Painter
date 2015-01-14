#include "stdafx.h"
#include "Point.h"
#include <Windows.h>
#include <iostream>
#pragma once
class NullShape:public Shape
{
	public:
		NullShape();
		NullShape(NullShape &);
		NullShape &operator=( NullShape &);
		~NullShape();//destructor
		void Paint(CDC *dc);

};