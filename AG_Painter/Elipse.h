#include "stdafx.h"
#include "Point.h"
#include <Windows.h>
#include <iostream>
#pragma once
class Elipse:public Point
{
	private:
		int x2;
		int y2;
	public:
		Elipse(int=0,int=0,int=0,int=0,int=0,COLORREF=0);//default constructor
		Elipse(Elipse &);//copy constructor
		~Elipse();//destructor
		Elipse &operator=(const Elipse &);
		void setX2(int);
		void setY2(int);
		int getX2() const;
		int getY2() const;
		void Paint(CDC *dc);
};