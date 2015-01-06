#include "stdafx.h"
#include "Document.h"

Drawer &Document::getDrawer()
{
	return *m_drawer;
}
void Document::setDrawer(Drawer &newDrawer)
{
	*m_drawer= newDrawer;
}

Shape &Document::getCurrentShape()
{
	return *currShape;
}
void Document::setCurrentShape(Shape &newShape)
{
	*currShape= newShape;
}
Document &Document::operator=(Document &newDocument)
{
	return newDocument;
}