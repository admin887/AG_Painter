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
	public:
		ShapesGarage(list<Shape*>* m_alive=nullptr,list<Shape*>* m_retired=nullptr);
		ShapesGarage(ShapesGarage &s);
		~ShapesGarage(void);
		//ShapesGarage &operator=(ShapesGarage &s);
		list<Shape*>* getAliveShapes();
		list<Shape*>* getRetiredShapes();
		void CreateShape(EnumShapes s);
};