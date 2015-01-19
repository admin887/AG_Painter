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
		int m_currWeight;
		ENUM_SHAPES m_Type;
		COLORREF m_currFill;
		COLORREF m_currLine;
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

		COLORREF getCurrFill();
		COLORREF getcurrLine();
		void setCurFill(COLORREF newCurFill);
		void setCurrLine(COLORREF newCurrLine);

		int getCurrWeight();
		void setCurrWeight(int newWight);

		void DeleteAlive();
		void DeleteRetired();



};