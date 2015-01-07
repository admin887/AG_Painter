#include "stdafx.h"
#include "Document.h"
#include "Drawer.h"
#pragma once;

Document::Document(Tool* newDrawer, Shape* newShape)
{
	setDrawer(*newDrawer);
	setCurrentShape(*newShape);
}
Tool &Document::getDrawer()
{
	return *m_drawer;
}
void Document::setDrawer(Tool &newDrawer)
{
	m_drawer= &newDrawer;
}

Shape &Document::getCurrentShape()
{
	return *currShape;
}
void Document::setCurrentShape(Shape &newShape)
{
	currShape= &newShape;
	getDrawer().setSelectedShape(currShape);
}
Document &Document::operator=(Document &newDocument)
{
	return newDocument;
}