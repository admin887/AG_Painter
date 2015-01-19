#include "stdafx.h"
#include "Point.h"
#include <Windows.h>
#include <iostream>
#pragma once
class Rec:public Shape
{
	DECLARE_SERIAL (Rec)
	public:
		Rec(Point newP1, Point newP2,int newWeight=1, COLORREF=0, COLORREF=0);
		Rec(int=0,int=0,int=0,int=0,int newWeight=1,COLORREF=0, COLORREF=0);//default constructor
		Rec(Rec &);//copy constructor
		~Rec();//destructor
		Rec &operator=( Rec &);
		void Paint(CDC *dc);

};