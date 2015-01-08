#include "stdafx.h"
#include "ShapesFactory.h"
bool ShapesFactory::instanceFlag = false;
ShapesFactory* ShapesFactory::s = nullptr;
ShapesFactory::ShapesFactory()
{
}
ShapesFactory::~ShapesFactory()
{
	instanceFlag=false;
}
ShapesFactory* ShapesFactory::getInstance()
{
	if(!instanceFlag)
	{
		s=new ShapesFactory();
		instanceFlag=true;
		return s;
	}
	else
		return s;
}
Shape* ShapesFactory::CreateShape(EnumShapes es)
{
	if(es==EnumShapes::E_POINT)
	{
		Point *p=new Point();
		return p;
	}
	else if(es==EnumShapes::E_LINE)
	{
		Line *l=new Line();
		return l;
	}
	else if(es==EnumShapes::E_ELI)
	{
		Elipse *e=new Elipse();
		return e;
	}
	else if(es==EnumShapes::E_REC)
	{
		Rec *r=new Rec();
		return r;
	}
}