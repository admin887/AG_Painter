#include "stdafx.h"
#include "Drawer.h"
#pragma once;
class Document
{
private:
	Drawer *m_drawer;
	Shape *currShape;
public:
	Drawer &getDrawer();
	void setDrawer(Drawer &newDrawer);

	Shape &getCurrentShape();
	void setCurrentShape(Shape &newShape);

	Document &operator=(Document &newDocument);
};