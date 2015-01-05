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
		int weight;
		COLORREF color;
	public:
		Point(int=0,int=0,int=1,COLORREF=0);//default constructor
		Point(Point &);//copy constructor
		~Point();//destructor
		const Point &operator=(const Point &);
		void setX(int);
		void setY(int);
		void setWeight(int);
		void setColor(COLORREF);
		int getX() const;
		int getY() const;
		int getWeight() const;
		COLORREF getColor() const;
		void Paint(CDC *dc);
		bool getIsSelected();
		void setIsSelected(bool);
};

enum Shapes {E_POINT, E_CIRCULE, E_RECTANGLE, E_LINE};