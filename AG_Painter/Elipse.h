#include "stdafx.h"
#include "Point.h"
#include <Windows.h>
#include <iostream>
#pragma once
class Elipse:public Shape
{
	DECLARE_SERIAL (Elipse)

	public:

		Elipse(Point newP1, Point newP2,int newWeight=1, COLORREF=0, COLORREF=0);
		Elipse(int=0,int=0,int=0,int=0,int newWeight=1,COLORREF=0, COLORREF=0);//default constructor
		Elipse(Elipse &);//copy constructor
		~Elipse();//destructor
		Elipse &operator=( Elipse &);
		void Paint(CDC *dc);
};