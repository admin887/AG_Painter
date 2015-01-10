#include "stdafx.h"
#include "Shape.h"
#include "ShapesFactory.h"
#include <list>
#pragma once
using namespace std;
class ShapesGarage
{
	private:
		list<Shape*> *m_alive;
		list<Shape*> *m_retired;
		ShapesFactory *m_factory;
		ENUM_SHAPES m_Type;
	public:
		ShapesGarage();
		ShapesGarage(ShapesGarage &s);
		~ShapesGarage(void);
		//ShapesGarage &operator=(ShapesGarage &s);
		list<Shape*>* getAliveShapes();
		list<Shape*>* getRetiredShapes();
		Shape* CreateShape(ENUM_SHAPES s);

		ENUM_SHAPES getTypeToConstract();
		void setTypeToConstrct(ENUM_SHAPES newType);


};