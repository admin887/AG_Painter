#include "stdafx.h"
#include "ShapesGarage.h"
#pragma once
ShapesGarage::ShapesGarage(list<Shape*>* m_alive,list<Shape*>* m_retired)
{
	m_alive=new list<Shape*>();
	//m_retired=new list<Shape>();
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
	ShapesFactory* sf=ShapesFactory::getInstance();
	m_alive->push_front(sf->CreateShape(s));
}