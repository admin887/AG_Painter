#include "stdafx.h"
#include "Document.h"
#include "Drawer.h"
#pragma once;

Document::Document(Tool* newCurTool, Shape* newShape)
{
	setCurrTool(*newCurTool);
	setCurrentShape(*newShape);
	sg= new ShapesGarage();
}
Tool &Document::getCurrTool()
{
	return *m_curTool;
}

void Document::setCurrTool(Tool &newCurTool)
{
	m_curTool=  &newCurTool;
}

Shape &Document::getCurrentShape()
{
	return *m_currShape;
}
void Document::setCurrentShape(Shape &newShape)
{
	m_currShape= &newShape;
	getCurrTool().setSelectedShape(m_currShape);
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
Document::~Document(void)
{

}

Document::Document(Document &newDoc)
{
	setCurrTool(newDoc.getCurrTool());
	setCurrentShape(newDoc.getCurrentShape());
}