#include "stdafx.h"
#include "ShapesFactory.h"
#include "NullShape.h"
ShapesFactory* ShapesFactory::s = nullptr;
ShapesFactory::ShapesFactory()
{
}
ShapesFactory::~ShapesFactory()
{

}
ShapesFactory* ShapesFactory::getInstance()
{
	if(s==nullptr)
	{
		s=new ShapesFactory();
		
		return s;
	}
	else
		return s;
}
Shape* ShapesFactory::CreateShape(ENUM_SHAPES es)
{
	if(es==E_POINT)
	{
		Point *p=new Point();
		return p;
	}
	else if(es==E_LINE)
	{
		Line *l=new Line();
		return l;
	}
	else if(es==E_ELIPSE)
	{
		Elipse *e=new Elipse();
		return e;
	}
	else if(es==E_RECTANGLE)
	{
		Rec *r=new Rec();
		return r;
	}

	return new NullShape();
}