#include "stdafx.h"
#include "Document.h"
Document::Document(Drawer &d,Shape &s)
{
	setDrawer(d);
	setCurrentShape(s);
}
Document::Document(Document &d)
{
	setDrawer(d.getDrawer());
	setCurrentShape(d.getCurrentShape());
}
Document &Document::operator=(Document &newDocument)
{
	return newDocument;
}
Drawer &Document::getDrawer()
{
	return *m_drawer;
}
void Document::setDrawer(Drawer &newDrawer)
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
