#include "stdafx.h"
#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"
#include "Elipse.h"
#include "Line.h"
#include "EnumShapes.h"
#pragma once
class ShapesFactory
{
private:
	static ShapesFactory* s;
	ShapesFactory();
public:
	~ShapesFactory();
	static ShapesFactory* getInstance();
	Shape* CreateShape(ENUM_SHAPES);
};