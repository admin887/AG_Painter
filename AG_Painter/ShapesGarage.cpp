#include "stdafx.h"
#include "ShapesGarage.h"
#include "ShapesFactory.h"
#pragma once
ShapesGarage::ShapesGarage(list<Shape*>* m_alive,list<Shape*>* m_retired, ShapesFactory *newFactory)
{
	m_alive=new list<Shape*>();
	//m_retired=new list<Shape>();
	*m_factory= *newFactory;
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
void ShapesGarage::CreateShape(EnumShapes s)
{
	m_factory = ShapesFactory::getInstance();
	m_alive->push_front(m_factory->CreateShape(s));
}