#include "stdafx.h"
#include "Shape.h"
#include <Windows.h>
#include <iostream>
#pragma once
class Point:public Shape
{
	private:
		int x;
		int y;
	public:
		Point(int=0,int=0,int=1,COLORREF=0);//default constructor
		Point(Point &);//copy constructor
		~Point();//destructor
		const Point &operator=(Point &);
		void setX(int);
		void setY(int);
		int getX() const;
		int getY() const;
		void Paint(CDC *dc);
};

enum Shapes {E_POINT, E_CIRCULE, E_RECTANGLE, E_LINE};