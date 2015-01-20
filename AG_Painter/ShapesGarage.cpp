#include "stdafx.h"
#include "ShapesGarage.h"
#include "ShapesFactory.h"
#pragma once
ShapesGarage::ShapesGarage()
{
	m_alive=new list<Shape*>();
	m_retired=new list<Shape*>();
	m_factory=nullptr;
}
ShapesGarage::ShapesGarage(ShapesGarage &s)
{
	m_alive=s.m_alive;
	m_retired=s.m_retired;
}
ShapesGarage::~ShapesGarage()
{
}
list<Shape*>* ShapesGarage::getAliveShapes()
{
	return m_alive;
}
list<Shape*>* ShapesGarage::getRetiredShapes()
{
	return m_retired;
}
Shape* ShapesGarage::CreateShape(ENUM_SHAPES s)
{
	Shape *myshape= m_factory->CreateShape(s);
	m_alive->push_front(myshape);
	return myshape;
}
ENUM_SHAPES ShapesGarage::getTypeToConstract()
{
	return m_Type;
}
void ShapesGarage::setTypeToConstrct(ENUM_SHAPES newType)
{
	m_Type= newType;
}

COLORREF ShapesGarage::getCurrFill()
	{
		return m_currFill;
	}
COLORREF ShapesGarage::getcurrLine()
	{
		return m_currLine;
	}
void ShapesGarage::setCurFill(COLORREF newCurFill)
	{
		m_currFill= newCurFill;
	}
void ShapesGarage::setCurrLine(COLORREF newCurrLine)
	{
		m_currLine= newCurrLine;
	}

int ShapesGarage::getCurrWeight()
{
	return m_currWeight;
}
void ShapesGarage::setCurrWeight(int newWight)
{
	m_currWeight= newWight;
}

void  ShapesGarage::DeleteAlive()
{
	Shape *s;
	int size= getAliveShapes()->size();

	for (int i = 0; i < size; i++)
	{
		s= getAliveShapes()->begin()._Mynode()->_Myval;
		getAliveShapes()->remove(s);
		delete s;
	}
}
void  ShapesGarage::DeleteRetired()
{
		Shape *s;
		int size= getRetiredShapes()->size();

		for (int i = 0; i < size; i++)
		{
		s= getRetiredShapes()->begin()._Mynode()->_Myval;
		getRetiredShapes()->remove(s);
		delete s;
		}
}