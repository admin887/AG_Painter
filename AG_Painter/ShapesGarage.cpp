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
	if(s==EnumShapes::E_POINT)
	{
		Point *p=new Point();
		m_alive->push_front(p);
	}
	else if(s==EnumShapes::E_LINE)
	{
		Line *l=new Line();
		m_alive->push_front(l);
	}
	else if(s==EnumShapes::E_ELI)
	{
		Elipse *e=new Elipse();
		m_alive->push_front(e);
	}
	else if(s==EnumShapes::E_REC)
	{
		Rec *r=new Rec();
		m_alive->push_front(r);
	}
}