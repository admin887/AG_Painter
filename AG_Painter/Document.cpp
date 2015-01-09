#include "stdafx.h"
#include "Document.h"
#include "Drawer.h"
#pragma once;

Document::Document(Tool* newCurTool, Shape* newShape)
{
	setCurrTool(*newCurTool);
	setCurrentShape(*newShape);

	//m_Selector= new Selector()
	//..
	//..
	sg= new ShapesGarage();
}
Tool &Document::getCurrTool()
{
	return *curTool;
}

void Document::setCurrTool(Tool &newCurTool)
{
	curTool=  &newCurTool;
}

Shape &Document::getCurrentShape()
{
	return *currShape;
}
void Document::setCurrentShape(Shape &newShape)
{
	currShape= &newShape;
	getCurrTool().setSelectedShape(currShape);
}
Document &Document::operator=(Document &newDocument)
{
	return newDocument;
}

ShapesGarage* Document::getShapeGarade()
	{
		return sg;
	}
void Document::setShapeGarade(ShapesGarage &newsg)
{
	sg= &newsg;
}