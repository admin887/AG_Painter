#include "stdafx.h"
#include "ShapesGarage.h"
#include "ShapesFactory.h"
#pragma once
//ShapesGarage::ShapesGarage(list<Shape*>* newalive,list<Shape*>* newretired, ShapesFactory *newFactory)
ShapesGarage::ShapesGarage()
{
	m_alive=new list<Shape*>();
	m_retired=new list<Shape*>();
	//*m_factory= *newFactory;
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
	//m_factory = ShapesFactory::getInstance();

	//Elipse *myeli= new Elipse();

	

	//m_alive=  new std::list<Shape*>();

	Shape *myshape= m_factory->CreateShape(s);

	m_alive->push_front(myshape);
	//m_alive->push_back(myshape);
	return myshape;
	//m_alive=  new std::list<Shape*>();

	//m_alive->push_front(myeli);






	//Elipse *e= new Elipse();
	//std::list<Shape*> *ssss= new std::list<Shape*>();

	//
	//ssss->push_front(e);

	

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
