#include "stdafx.h"
#include "Point.h"
#include <Windows.h>
#include <iostream>
#pragma once
class Rec:public Point
{
	private:
		int x2;
		int y2;
	public:
		Rec(int=0,int=0,int=0,int=0,int=0,COLORREF=0);//default constructor
		Rec(Rec &);//copy constructor
		~Rec();//destructor
		Rec &operator=(const Rec &);
		void setX2(int);
		void setY2(int);
		int getX2() const;
		int getY2() const;
		void Paint(CDC *dc);
		bool getIsSelected();
		void setIsSelected(bool);
};