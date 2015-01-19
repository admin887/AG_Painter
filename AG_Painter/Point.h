#include "stdafx.h"
#include "Shape.h"
#include <Windows.h>
#include <iostream>
#pragma once
class Point:public Shape
{
	DECLARE_SERIAL (Point)
	public:
		Point(int=0,int=0,int=4,COLORREF=0);//default constructor
		Point(Point &);//copy constructor
		~Point();//destructor
		const Point &operator=(Point &);
		void Paint(CDC *dc);
};
